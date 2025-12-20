#include<stdio.h>
#include<errno.h>   // for errno
#include<fcntl.h>   // open
#include<string.h>  // strerror

int main()
{
    int fd = 0;

    fd = open("Marvellous.txt",O_RDONLY);

    printf("Valaue of fd is :  %d\n",fd);

    if(errno != 0)
    {
        switch(errno)
        {
            case ENOENT:
                printf("Their is no such file .create the file and open\n");
                break;

            case EACCES:
                printf("Unable to access as there is no permission\n");
                break;

            default:
                printf("%s\n",strerror(errno));
        }
    }

    return 0;
}