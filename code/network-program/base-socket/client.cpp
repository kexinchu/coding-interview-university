/***
创建一个简单的客户端
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
    if (argc != 3)
    {
        printf("Using:./client ip port\nExample:./client 127.0.0.1 5005\n\n");
        return -1;
    }

    // 第1步：创建客户端的socket。
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        return -1;
    }

    // 第2步：向服务器发起连接请求。
    struct hostent *h;
    // struct hostent *gethostbyname(const char *name)  // 可以解析域名主机名，功能比inet_addr更强大(只支持ip地址)
    if ((h = gethostbyname(argv[1])) == 0)
    { // 获取服务端的ip地址。
        printf("gethostbyname failed.\n");
        close(sockfd);
        return -1;
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));           // 指定服务端的通信端口。
    memcpy(&servaddr.sin_addr, h->h_addr, h->h_length); // 指定服务端的IP地址
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    { // 向服务端发起连接清求。
        perror("connect");
        close(sockfd);
        return -1;
    }

    char buffer[1024];
    // 第3步：与服务端通信，发送一个报文后等待回复，然后再发下一个报文。
    for (int ii = 0; ii < 10; ii++)
    {
        int iret;
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "这是第%d个报文，编号%03d。", ii + 1, ii + 1);
        if ((iret = send(sockfd, buffer, strlen(buffer), 0)) <= 0)
        { // 向服务端发送请求报文。
            perror("send");
            break;
        }
        printf("发送：%s\n", buffer);

        memset(buffer, 0, sizeof(buffer));
        if ((iret = recv(sockfd, buffer, sizeof(buffer), 0)) <= 0)
        { // 接收服务端的回应报文。
            printf("iret=%d\n", iret);
            break;
        }
        printf("接收：%s\n", buffer);

        sleep(1);
    }

    // 第4步：关闭socket，释放资源。
    close(sockfd);
}