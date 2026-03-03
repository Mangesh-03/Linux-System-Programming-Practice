// ServerCode

#include<stdio.h>           // printf scanf
#include<stdlib.h>          // malloc free
#include<string.h>          // memset memcmp

#include<unistd.h>          // close write read
#include<fcntl.h>           // creat unlink

#include<sys/socket.h>      // socket accept bind listen connect
#include<netinet/in.h>      // sockaddr_in ,htons

// /*
// struct sockaddr_in 
//       {
//            sa_family_t     sin_family;     /* AF_INET */
//            in_port_t       sin_port;       /* Port number */
//            struct in_addr  sin_addr;       /* IPv4 address */
//        };
// */

int main()
{
    int ServerSocket = 0;
    int iRet = 0;
    int ClientSocketfd = 0;
    int port = 11000;

    struct sockaddr_in ServerAddr;

    // 1 : create TCP socket           SOCK_STREAM=> refer TCP socket 
    ServerSocket = socket(AF_INET,SOCK_STREAM,0);

    if(ServerSocket < 0)
    {
        printf("Unable to create socket\n");
        return -1;
    }

    printf("Socket gets creted succesfully with fd : %d\n",ServerSocket);

    // set memory with 0
    memset(&ServerAddr,0,sizeof(ServerAddr));

    // Initialising the struct 
    ServerAddr.sin_family =  AF_INET;
    ServerAddr.sin_addr.s_addr =  INADDR_ANY;
    ServerAddr.sin_port = htons(port);

    // 2 : Attach socket to the ipAddr and port number.
    iRet = bind(ServerSocket,(struct sockaddr*) &ServerAddr,sizeof(ServerAddr));

    if(iRet ==  -1)
    {
        printf("bind sys call failed\n");
        close(ServerSocket);
        return -1;
    }

    printf("Bind operation with socket is successful\n");

    // 3 : Mark the socket as active socket
    iRet = listen(ServerSocket,11);

    if(iRet == -1)
    {
        printf("Unble to convert socket in listen mode\n");
        return -1;
    }

    printf("Server is live at port %d\n",port);

    // 4 : Accept new socket request
    ClientSocketfd = accept(ServerSocket,NULL,NULL);

    if(ClientSocketfd == -1)
    {
        printf("Unble to accept request from client\n");
        return -1;
    }

    printf("Request accepted by server\n");

    return 0;
}