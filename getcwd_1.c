#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

int main()
{
    printf("Current dir name : %s\n",getcwd()); //Error -> too few arg
   
    return 0;
}