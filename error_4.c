#include<stdio.h>
#include<errno.h>   // for errno
#include<fcntl.h>   // open
#include<string.h>  // strerror

int main()
{
    int fd = 0;

    fd = open("Demo.txt",O_RDONLY);

    printf("Valaue of fd is :  %d\n",fd);

    if(errno != 0)
    {
        printf("Value of errno is : %d\n",errno);
        printf("Error Statement : %s\n",strerror(errno));
    }

    return 0;
}