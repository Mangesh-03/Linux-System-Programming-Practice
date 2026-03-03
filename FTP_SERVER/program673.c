// ClientCode

#include<stdio.h>           // printf scanf
#include<stdlib.h>          // malloc free
#include<string.h>          // memset memcmp

#include<unistd.h>          // close write read
#include<fcntl.h>           // creat unlink

#include<sys/socket.h>      // socket accept bind listen connect
#include<netinet/in.h>      // sockaddr_in ,htons

#include<arpa/inet.h>

int main()
{
    int ServerSocketfd = 0;
    int iRet = 0;
    int port = 11000;
    
    struct sockaddr_in ServerAddr;

    char buffer[1024] = {'\0'};

    // 1 : Create TCP socket
    ServerSocketfd = socket(AF_INET,SOCK_STREAM,0);

    if(ServerSocketfd < 0)
    {
        printf("Unble to create socket\n");
        return -1;
    }

    printf("Socket get created successfully with fd : %d\n",ServerSocketfd);

    // 2 : Connect with server
    memset(&ServerAddr,0,sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(port);
    
    // 127.0.0.1 -> binary form
    inet_pton(AF_INET,"127.0.0.1",&ServerAddr.sin_addr);
    
    iRet = connect(ServerSocketfd,(struct sockaddr *)&ServerAddr,sizeof(ServerAddr));

    if(iRet == -1)
    {
        printf("Unble to connect with server\n");
        return -1;
    }

    printf("Client successfully connected with server\n");

    // 3 : Read data from server
    iRet = read(ServerSocketfd,buffer,sizeof(buffer) - 1);

    if(iRet <= 0)
    {
        printf("Unble to read the data from server\n");
        return -1;
    }

    printf("Data from server is : %s\n",buffer);

    // 4 : close all resources
    close(ServerSocketfd);

    printf("Terminating the client application\n");

    return 0;
}