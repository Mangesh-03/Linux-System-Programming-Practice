//Server Code

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

///////////////////////////////////////////////////////////////////////////////
//
//  CommandLine Argument Application
//
//  1st Arguent : Port Number
//
//  ./server     9000
//   argv[0]    argv[1]
//
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    int Port = 0;
    int ServerSocket = 0;
    int ClientSocket = 0;
    int iRet = 0;

    struct sockaddr_in ServerAddr;
    struct sockaddr_in ClientAddr;
    
    socklen_t AddLen = sizeof(ClientAddr);

    if((argc < 2) || (argc > 2))
    {
        printf("Unble to processed as invalid number of argument\n");

        printf("Please provide : \n");
        printf("\nPort Number : \n");
    }

    // Port Number of server
    Port = atoi(argv[1]);

    ///////////////////////////////////////////////////////////////////////////
    //   
    //  step 1 : Create TCP socket
    //
    ///////////////////////////////////////////////////////////////////////////


    ServerSocket = socket(AF_INET,SOCK_STREAM,0);

    if(ServerSocket == -1)
    {
        printf("Unble to create server socket\n");
        return -1;
    }
    //////////////////////////////////////////////////////////////////////////
    //  step 2 : Bind socket
    ///////////////////////////////////////////////////////////////////////////

    memset(&ServerAddr,0,sizeof(ServerAddr));

    // Initialise structure
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);
    ServerAddr.sin_addr.s_addr = INADDR_ANY;

    iRet = bind(ServerSocket,(struct sockaddr*) &ServerAddr,sizeof(ServerAddr));

    if(iRet == -1)
    {
        perror("Unble to bind");
        close(ServerSocket);
        return -1;
    }

    //////////////////////////////////////////////////////////////////////////
    //  step 3 : Listen for client connection
    ///////////////////////////////////////////////////////////////////////////

    iRet = listen(ServerSocket,11);

    if(iRet == -1)
    {
        perror("Server unble to listen request");
        close(ServerSocket);
        return -1;
    }

    printf("Server is running on port : %d\n",Port);

    return 0;
}
