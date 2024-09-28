#### C++ 实现简单socket编程

##### 参考
    https://freecplus.net/0047ac4059b14d52bcc1d4df6ae8bb83.html

##### 执行
```
make
./server ${Port}
./client ${ip} ${Port}
```

##### socket中的结构体
- [ ] socketaddr
    - 16字节
    - 常用于bind、connect、recv、send等函数的入参，指明地址信息，是一种通用的套接字地址。
    ```
    struct socketaddr {
        unsigned short sa_family;   // 地址类型： 域协议
        char sa_data[14];           // 14字节的端口和地址
    }
    ```
- [ ] socketaddr_in
    - 16字节
    - 是internet环境下套接字的地址形式；
    - 在网络编程中我们会对sockaddr_in结构体进行操作，使用sockaddr_in来建立所需的信息(赋值)；强制类型转换后传入用sockaddr做参数的函数
        - sockaddr_in用于socket定义和赋值；sockaddr用于函数参数。
    ```
    struct socketaddr_in {
        short int sin_family;           // 地址类型： 域协议
        unsigned short int sin_port;    // 端口号
        struct in_addr sin_addr;        // 地址
        unsigned char sin_sero[14];     // 为了保持与struct socketaddr一样长; 方便相互转化
    }

    // 4字节
    struct in_addr {
        unsigned long s_addr;           // 地址
    }
    ```
- hostent
    ```
    struct hostent {
        char *h_name;           // 主机名
        char **h_aliases;       // 主机所有别名构成的字符串数组；同一个ip可以绑定多个域名
        int h_addrtype;         // 主机IP低质的类型，例如IPV4(AF_INET)
        int h_length;           // 主机IP低质长度, IPV4 => 4;  IPV6 => 16
        char **h_addr_list;     // 主机的IP地址，以网络字节序存储
    }
    #define h_addr h_addr_list[0] /* for backward compatibility */
    ```


##### 函数 & 注意事项
- [ ] 声明一个socket
    - int socket(int domain, int type, int protocol);
        - domain: 指定域协议，决定socket的地址类型; AF_INET表示使用IPv4协议
        - type: 指定socket类型； SOCK_STREAM表示Tcp连接，提供序列化的、可靠的、双向连接的字节流。支持带外数据传输
        - protocol: 指定协议，当protocol=0时表示会自动选择跟type类型对应的默认协议
    ```
    int listenfd;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        return -1;
    }
    ```

- [ ] 把服务端用于通信的地址和端口绑定到socket上
    - int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
        - 参数sockfd，需要绑定端口和IP的socket变量
        - 参数addr，sockaddr结构体变量, 存放了待绑定的IP和端口。
        - 参数addrlen，表示addr结构体的大小。
        - 返回值：成功则返回0，失败返回-1，错误原因存于errno 中。
    - 如果绑定的地址错误，或端口已被占用，bind函数一定会报错，否则一般不会返回错误。
    - 端口号限制: 65535
        - Linux系统中c代码写的端口号port的变量占16位 => 0 ~ 65535(2^16)
        - 熟知端口号: 0-1023，比如 HTTP 使用 80端口，HTTPS 使用 443 端口，ssh 使用 22 端口
        - 已登记端口号: 1024-49151 (IANA登记)
        - 临时端口号:  49152-65535; 这些端口可以供本地程序临时分配端口使用，一般的如果应用程序没有调用bind函数为socket绑定一个端口，那么系统会为该 socket 分配一个唯一的临时端口
        - 临时端口号范围可以查看和更改
            ```
            // 查看
            cat /proc/sys/net/ipv4/ip_local_port_range
            // 修改
            sysctl -w net.ipv4.ip_local_port_range="50000 50010"
            ```
        - 0号端口可用吗？
            - socket中，为端口号赋值0，表示INADDR_ANY; 即内核会随机分配一个端口号给socket
    - TIME_WAIT
        - 根据四次挥手协议，主动断开链接的一方会进入TIME_WAIT的状态，等待另一方的挥手确认。它会继续占用端口一小段时间。
        - 导致断开的端口不能立即投入使用会 *** bind会报错 ***
        <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/4-times-handwave.jpg" width="300px">
    - 示例
    ```
    struct sockaddr_in servaddr;                  // 声明存放服务端地址信息的数据结构。
    memset(&servaddr, 0, sizeof(servaddr));       // memset 使用0来对&servaddr进行初始化
    servaddr.sin_family = AF_INET;                // 协议族，在socket编程中只能是AF_INET。
    // 任意ip地址; 使用网络字节顺序
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    // 指定ip地址
    //servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); 
    // 指定通信端口, 使用网络字节顺序
    servaddr.sin_port = htons(atoi(argv[1]));

    // int band(int, const sockaddr, socklen_t) 规定的入参格式，需要将servaddr转换成sockaddr* 再传入
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        perror("bind");
        close(listenfd);
        return -1;
    }
    ```
    
- [ ] 客户端程序 指定服务端的ip地址 和 端口 并发送连接请求
    - int connect(int sockfd, struct sockaddr * serv_addr, int addrlen);
    ```
    struct hostent *h;
    if ((h = gethostbyname("192.168.149.129")) == 0) {    // 获取服务端的IP地址
        printf("gethostbyname failed.\n");
        close(sockfd);
        return -1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi("8080"));  // 指定服务端的通信端口。
    memcpy(&servaddr.sin_addr, h->h_addr, h->h_length); // 指定服务端的ip地址。

     if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) { // 向服务端发起连接清求。
        perror("connect");
        close(sockfd);
        return -1;
    }
    ```

- [ ] listen函数 —— 设置监听socket，接收客户端请求
    - int listen(int sockfd, int backlog);
        - listen函数把主动连接socket变为被动连接的socket，使得这个socket可以接受其它socket的连接请求，从而成为一个服务端的socket。
        - backlog 表示 等待accept的完全建立的套接字的队列长度 (参考三次握手进行解释)
            - 根据三次握手，服务端接收的连接可分为半连接态(SYN_RECV) 和 连接态(ESTABLISTED) 两种；Linux内核会为这两种状态的socket维护两个队列。
            - backlog就是ESTABLISHED队列的长度
            <img src="https://github.com/kexinchu/coding-interview-university/blob/main/pictures/3-times-handshake.jpg" width="800px">
        - 查看队列情况
        ```
        // 通过netstat命令查看
        netstat -na | grep ${port}
        ```

- [ ] accpet函数 - 从listen的ESTABLISTED队列中获取一个连接请求，并绑定一个新的socket与其进行通信
    - int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
        - 参数sockfd: 表示被listen过的socket。
        - 参数addr: 用于存放客户端的地址信息，用sockaddr结构体表达，如果不需要客户端的地址，可以填0。
        - 参数addrlen: 用于存放addr参数的长度，如果addr为0，addrlen也填0。
    - 参与listen的socket不能用于跟客户端通信，所以建立连接时(accept())要创建新的socket来完成通信
    ```
    // 第4步：接受客户端的连接。
    int clientfd;                             // 客户端的socket。
    int socklen = sizeof(struct sockaddr_in); // struct sockaddr_in的大小
    struct sockaddr_in clientaddr;            // 客户端的地址信息。
    clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t *)&socklen);
    ```

- [ ] send()/recv()函数 - 收发数据
    - ssize_t send(int sockfd, const void *buf, size_t len, int flags);
        - sockfd为已建立好连接的socket。
        - buf为需要发送的数据的内存地址，可以是C语言基本数据类型变量的地址，也可以数组、结构体、字符串，内存中有什么就发送什么。
        - len需要发送的数据的长度，为buf中有效数据的长度。
        - flags填0, 其他数值意义不大。
    - 发送缓冲区；使用send方法时会先检查发送缓冲区;
        - 待发送数据长度比缓冲区长度还大时，返回 *** SOCKET_ERROR *** 错误
        - 否则:
            - 发送缓冲区为空 or 缓冲区剩余大小>待发送数据长度；send()将待发送的数据拷贝至该缓冲区中，并返回copy数据的长度
            - 缓冲区剩余大小 < 待发送数据长度；等待至缓冲区内数据发送完，开始拷贝操作

    - ssize_t recv(int sockfd, void *buf, size_t len, int flags);
        - sockfd为已建立好连接的socket。
        - buf为用于接收数据的内存地址，可以是C语言基本数据类型变量的地址，也可以数组、结构体、字符串，只要是一块内存即可。
        - len表示需要接收的数据长度，不能超过buf的大小，否则内存溢出。
        - flags填0, 其他数值意义不大。
    - 接收数据过程：
        - 1，recv()被调用时，会先等待sockfd中发送缓冲区的协议发送完数据，如果在等待过程中出现网络错误，则会返回SOCKET_ERROR。
        - 2，如果sockfd中的发送缓冲区中没有数据或者协议已经发送完数据了，则recv()会检查sockfd的接受缓冲区：
            - 如果接受缓冲区正在接受数据，则recv会一直等待，直到缓冲区接受数据完毕，之后recv将数据从缓冲区拷贝一份到buf中。
    - 错误值：如果recv在拷贝数据时出现错误，则返回SOCKET_ERROT,如果在协议传输数据中出现网络错误，则返回0。
    
    - *** 不管是send() 还是 recv() 都是与发送缓冲区和接收缓冲区的数据copy过程，真正发送和接收数据的是协议功能 ***
    - 返回值：-1表示出错，0表示超时,即对方主动关闭了连接过程，>0表示成功，具体数值是发送/接收数据的长度。

##### 注意事项
    - Linux是基于文件的，系统有设置单一程序打开的文件数限制，这也就限制了单一程序能创建的socket数(本质上，linux下socket也是一个文件)
        - 查看当前操作系统已经打开的文件总量cat /proc/sys/fs/file-nr 注：第一个值是已开启的，第二个值是分配但未使用，第三个值是总限制数
        ```
        1504    0       3248353
        ```
        - 查看操作系统允许打开的文件总量限制cat /proc/sys/fs/file-max
        ```
        3248353
        ```
        - 查看进程可以打开的文件数量限制ulimit -a
        ```
        core file size          (blocks, -c) unlimited
        data seg size           (kbytes, -d) unlimited
        file size               (blocks, -f) unlimited
        pending signals                 (-i) 128043
        max locked memory       (kbytes, -l) 64
        max memory size         (kbytes, -m) unlimited
        open files                      (-n) 10240
        pipe size            (512 bytes, -p) 8
        POSIX message queues     (bytes, -q) 819200
        stack size              (kbytes, -s) 8192
        cpu time               (seconds, -t) unlimited
        max user processes              (-u) 128043
        virtual memory          (kbytes, -v) unlimited
        file locks                      (-x) unlimited
        ```

    - 网络字节序 & 本地字节序
        - 计算机字节序分为 *** 大端 & 小端 *** 两种；（早期系统设计标准造成的）
            - 大端: 数据超出1个字节时，将数据的高位存放在内存的低地址处
            - 小端: 数据超出1个字节时，将数据的低位存放在内存的低地址处
        - 为了使不同机器之间的数据交互不产生"歧义", 统一使用网络字节序(大端)
            - htons() 和 ntohs() 实现16位无符号数据转换
            - htonl() 和 ntohl() 实现32位无符号数据转换
        ```
        servaddr.sin_port = htons(atoi(argv[1]));    // 指定通信端口, 使用网络字节顺序
        ```
    
    - 分包和粘包
        - TCP协议是基于字节流并且无边界的传输协议, 因此很有可能产生分包和粘包问题；
        - 发送方引起的粘包是由TCP协议本身造成的，TCP为提高传输效率，发送方往往要收集到足够多的数据后才发送一个TCP段。若连续几次需要send的数据都很少，通常TCP会根据优化算法把这些数据合成一个TCP段后一次发送出去，但是接收方并不知道要一次接收多少字节的数据，这样接收方就收到了粘包数据。
        ```
        // 模拟可以通过指定不同的发送和接收字节长度时，来模拟
        // send() - 每次发送44个字节的内容
        sprintf(buffer, "这是第%d个报文，编号%03d。", ii + 1, ii + 1);
        if ((iret = send(sockfd, buffer, strlen(buffer), 0)) <= 0)
        { // 向服务端发送请求报文。
            perror("send");
            break;
        }

        // recv() - 当选择接收1024个字节的内容时; 就会在服务端看到客户端发送的包被切割和
        int iret;
        memset(buffer, 0, sizeof(buffer)); // 初始化为0
        if ((iret = recv(clientfd, buffer, 1024, 0)) <= 0)
        { // 接收客户端的请求报文。
            printf("iret=%d\n", iret);
            break;
        }
        ```
        - 如何解决分包和粘包问题: 需要自定义一份协议
            - 常用方法：报文长度+报文内容   0010helloworld
