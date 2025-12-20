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
    char path[50] ;
    memset(path,'\0',sizeof(path));

    getcwd(path,sizeof(path));

    printf("Current dir name : %s\n",path); 
    chdir("./Data");

    getcwd(path,sizeof(path));
    printf("Current dir name : %s\n",path);
    
    return 0;
}