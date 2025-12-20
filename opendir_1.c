#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>   
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>

int main()
{
    DIR * dp = opendir("./Data");
    
    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
    else{
        printf("Directory gets Successfully open\n");
    }

    return 0;
}