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

    memset(Buffer,'\0',SIZE_BUFFER);     

    fd = open("Hole.txt",O_WRONLY | O_CREAT);

    if(fd < 0)
    {
        printf("Unable to open file for writing\n");
        printf("Reason : %s",strerror(errno));
        return -1;
    }

    printf("File successfully open with fd %d\n",fd);

    iRet = lseek(fd,4100,SEEK_SET);
    printf("Current offset is : %d\n",iRet);

    iRet = write(fd,"End",3);
    printf("%d bytes gets written Successfuly\n",iRet);

    close(fd);
    return 0;
}

//page.cis -> swap memory