/***
实现一个简单的服务端
***/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Using:./server port\nExample:./server 5005\n\n");
        return -1;
    }

    // 第1步：创建服务端的socket。
    /***
    int socket(int domain, int type, int protocol);
        domain: 指定域协议，决定socket的地址类型; AF_INET表示使用IPv4协议
        type: 指定socket类型； SOCK_STREAM表示Tcp连接，提供序列化的、可靠的、双向连接的字节流。支持带外数据传输
        protocol: 指定协议，当protocol=0时表示会自动选择跟type类型对应的默认协议
    ***/
    int listenfd;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        return -1;
    }

    // 第2步：把服务端用于通信的地址和端口绑定到socket上。
    struct sockaddr_in servaddr;                  // 声明存放服务端地址信息的数据结构。
    memset(&servaddr, 0, sizeof(servaddr));       // memset 使用0来对&servaddr进行初始化
    servaddr.sin_family = AF_INET;                // 协议族，在socket编程中只能是AF_INET。
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // 任意ip地址。
    //servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); // 指定ip地址
    servaddr.sin_port = htons(atoi(argv[1])); // 指定通信端口, 使用网络字节顺序

    // int band(int, const sockaddr, socklen_t) 规定的入参格式，需要将servaddr转换成sockaddr* 再传入
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        perror("bind");
        close(listenfd);
        return -1;
    }

    // 第3步：把socket设置为监听模式。
    // listen函数把主动连接socket变为被动连接的socket，使得这个socket可以接受其它socket的连接请求，从而成为一个服务端的socket。
    if (listen(listenfd, 5) != 0)
    {
        perror("listen");
        close(listenfd);
        return -1;
    }

    // 第4步：接受客户端的连接: accpet从listen队列中获取一个链接请求，如果队列为空，accpet函数将阻塞等待
    int clientfd;                             // 客户端的socket。
    int socklen = sizeof(struct sockaddr_in); // struct sockaddr_in的大小
    struct sockaddr_in clientaddr;            // 客户端的地址信息。
    clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t *)&socklen);
    printf("客户端（%s）已连接。\n", inet_ntoa(clientaddr.sin_addr));

    // 第5步：与客户端通信，接收客户端发过来的报文后，回复ok。
    char buffer[1024]; // 声明buffer存放接收字客户端的报文和将要发送给客户端的
    while (1)
    {
        int iret;
        memset(buffer, 0, sizeof(buffer)); // 初始化为0
        if ((iret = recv(clientfd, buffer, sizeof(buffer), 0)) <= 0)
        { // 接收客户端的请求报文。
            printf("iret=%d\n", iret);
            break;
        }
        printf("接收：%s\n", buffer);

        strcpy(buffer, "ok"); //
        if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0)
        { // 向客户端发送响应结果； ok
            perror("send");
            break;
        }
        printf("发送：%s\n", buffer);
    }

    // 第6步：关闭socket，释放资源。
    close(listenfd);
    close(clientfd);
}