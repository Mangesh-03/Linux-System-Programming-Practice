#include<fcntl.h>       //open
#include<stdio.h>       
#include <unistd.h>     //close

int main()
{
    int fd = 0;

    fd = open("Second.c",O_CREAT | O_TRUNC ,0777);

    if(fd == -1)
    {
        printf("Unable to created file\n");
    }
    else
    {
        printf("Files gets succesffully created with fd : %d\n",fd);
    }

    close(fd);

    return 0;
}