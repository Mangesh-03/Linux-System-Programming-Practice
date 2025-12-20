#include<stdio.h>
#include<errno.h>   // for errno
#include<fcntl.h>   // open
#include<string.h>  // strerror

int main()
{
    int fd = 0;

    fd = open("Marvellous.txt",O_RDONLY);

    printf("Valaue of fd is :  %d\n",fd);

    printf("Value of errno is : %d\n",errno);
    printf("Error Statement : %s\n",strerror(errno));

    return 0;
}

// program should handled : 
//return value
//error no
//