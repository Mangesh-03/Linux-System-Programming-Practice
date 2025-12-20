#include<stdio.h>
#include<fcntl.h>

int main(int agrc,char *argv[])
{
    int fd = 0;

    fd = creat(argv[1],0777);

    if(fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File gets successfully created with fd : %d \n",fd);
    }
    
    return 0;
}