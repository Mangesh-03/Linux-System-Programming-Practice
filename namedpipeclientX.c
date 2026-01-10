// NamedPipe Client

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0,iRet = 0;
    char Arr[100] = {'\0'};

    fd = open("/tmp/marvellous",O_RDONLY);

    if(fd == -1)
    {
        printf("unable to named pipe\n");
        return -1;
    }

    read(fd,Arr,3);    

    printf("Data gets sucessfully read from the pipe by client\n");
    printf("Data is : %s \n",Arr);

    close(fd);

    return 0;
}