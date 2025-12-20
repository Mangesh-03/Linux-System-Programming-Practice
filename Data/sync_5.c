#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>   
#include<string.h>
#include<errno.h>

int main()
{
    int fd = 0;
    char Buffer[] = "Indiaismycountry";
    int iRet = 0;

    fd = open("Demo.txt",O_WRONLY | O_APPEND | O_CREAT,0777);   

    if(fd < 0)
    {
        printf("Unable to open file for writing\n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File successfully open with fd %d\n",fd);

    iRet = write(fd,Buffer,16);     
    
    printf("%d bytes gets successfully written\n",iRet);
    
    fdatasync(fd);  // writes only data block
    //process is in waiting state
    
    close(fd);

    return 0;
}