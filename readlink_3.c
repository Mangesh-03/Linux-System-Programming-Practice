#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
    char path[100];
    int iRet = 0;
    int fd = 0;
    char Arr[20];

    // memset(Arr,'\0',sizeof(Arr));
    memset(path,'\0',sizeof(path));

    iRet = readlink("./test/LSPl.txt",path,sizeof(path));

    if(iRet == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    path[iRet] = '\0';
    
    printf("Data from readlink is : %s\n",path);

    fd = open(path,O_RDONLY);

    if(fd == -1)
    {
        printf("unable to open file : %s\n",strerror(errno));
        return -1;
    }

    iRet = read(fd,Arr,10);

    Arr[iRet] = '\0';

    printf("Data from original file is : %s\n",Arr);
    close(fd);

    return 0;
}