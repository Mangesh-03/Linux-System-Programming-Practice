#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>   
#include<string.h>
#include<errno.h>

#define SIZE_BUFFER 100

int main()
{
    int fd = 0;
    char Buffer[SIZE_BUFFER] ;
    int iRet = 0;

    memset(Buffer,'\0',SIZE_BUFFER);    // Change 

    fd = open("Demo.txt",O_RDONLY);

    if(fd < 0)
    {
        printf("Unable to open file for writing\n");
        printf("Reason : %s",strerror(errno));
        return -1;
    }

    printf("File successfully open with fd %d\n",fd);

    iRet = read(fd,Buffer,10);     
    
    printf("%d bytes gets successfully read\n",iRet);
    printf("Data from file is : %s \n",Buffer);

    close(fd);

    return 0;
}