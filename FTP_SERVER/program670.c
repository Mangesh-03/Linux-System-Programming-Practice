// ClientCode

#include<stdio.h>           // printf scanf
#include<stdlib.h>          // malloc free
#include<string.h>          // memset memcmp

#include<unistd.h>          // close write read
#include<fcntl.h>           // creat unlink

#include<sys/socket.h>      // socket accept bind listen connect
#include<netinet/in.h>      // sockaddr_in ,htons

int main()
{
    int ServerSocketfd = 0;

    //1 : Create TCP socket
    ServerSocketfd = socket(AF_INET,SOCK_STREAM,0);

    if(ServerSocketfd < 0)
    {
        printf("Unble to create socket\n");
        return -1;
    }

    printf("Socket get created successfully with fd : %d\n",ServerSocketfd);



    return 0;
}