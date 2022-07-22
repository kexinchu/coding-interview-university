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


##### 函数
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

- [ ] 绑定IP + Port
    - 指定固定ip
    ```
    m_servaddr.sin_addr.s_addr = inet_addr("192.168.149.129");  // 指定ip地址
    ```
    - 指定任意ip
    ```
    m_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);  // 本主机的任意ip地址
    ```

    - 指定服务端的通信端口，这里使用了网络字节顺序<服务端和客户端要保持一致，要么都用，要么都不用>
    ```
    servaddr.sin_port = htons(atoi(argv[1]));   // 指定通信端口, 使用网络字节顺序
    ```
    
- [ ] 客户端程序 指定服务端的ip地址 和 端口
    ```
    struct hostent *h;
    if ((h = gethostbyname("192.168.149.129")) == 0)
    { // 指定服务端的ip地址。
        printf("gethostbyname failed.\n");
        close(sockfd);
        return -1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2])); // 指定服务端的通信端口。
    memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);
    ```

- [ ] listen函数
    - listen函数把主动连接socket变为被动连接的socket，使得这个socket可以接受其它socket的连接请求，从而成为一个服务端的socket。
    - socket listen之后就可以被客户端连接了，但服务端处理客户端数据是从accept之后开始的
    - listen的socket不能用于跟客户端通信，所以建立连接时(accept())要创建新的socket来完成通信
    ```
    // 第4步：接受客户端的连接。
    int clientfd;                             // 客户端的socket。
    int socklen = sizeof(struct sockaddr_in); // struct sockaddr_in的大小
    struct sockaddr_in clientaddr;            // 客户端的地址信息。
    clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t *)&socklen);
    ```

- [ ] recv()函数
    - 返回值是接收的字符串长度，失败为-1


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
        