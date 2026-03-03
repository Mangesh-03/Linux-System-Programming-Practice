// Client application

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
//  1st Arguent : IP Address
//  2nd Arguent : Port Number
//  3rd Arguent : Target File name
//  4th Arguent : New file name
//
//  ./client    127.0.0.1     9000       Demo.txt      A.txt
//   argv[0]    argv[1]       argv[2]    argv[3]       argv[4]
//
//  agrc = 5
//
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    int Port = 0;                   // argv[2]
    int Sock = 0;
    int iRet = 0;
    
    char *Filename = NULL;          // argv[3]
    char *OutFilename = NULL;       // argv[4]
    char *IP = NULL;                // argv[1]
    
    struct sockaddr_in ServerAddr;

    if((argc < 5) || (argc > 5))
    {
        printf("Unble to processed as invalid number argument\n");

        printf("Please provide below arguments\n");

        printf("1st Arguent : IP Address\n");
        printf("2nd Arguent : Port Number\n");
        printf("3rd Arguent : Target File name\n");
        printf("4th Arguent : New file name\n");

        return -1;
    }

    // Store command line argument 
    IP = argv[1];
    Port = atoi(argv[2]);
    Filename = argv[3];
    OutFilename = argv[4];

    ///////////////////////////////////////////////////////////////////////////
    //  step 1 : Create TCP socket
    ///////////////////////////////////////////////////////////////////////////

    Sock = socket(AF_INET,SOCK_STREAM,0);

    if(Sock < 0)
    {
        perror("Unble to create client socket");
        return -1;
    }

    ///////////////////////////////////////////////////////////////////////////
    //  step 2 : Connet with server
    ///////////////////////////////////////////////////////////////////////////

    memset(&ServerAddr,0,sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(Port);

    // Convert the IP address into binary format
    inet_pton(AF_INET,IP,&ServerAddr.sin_addr);

    iRet = connect(Sock,(struct sockaddr*)&ServerAddr,sizeof(ServerAddr));
    
    if(iRet == -1)
    {
        perror("Unble to connect with server");
        close(Sock);
        return -1;
    }
    
    // Sending file name
    write(Sock,Filename,strlen(Filename));

    return 0;

}//End of main