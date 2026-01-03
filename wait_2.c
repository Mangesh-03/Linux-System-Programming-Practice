#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int status = 0;
    pid_t pid = 0;
    pid_t x = 0;

    pid = fork();

    if(pid == 0)    //child
    {
        sleep(10);
        exit(21);
    }
    
    x = wait(&status);

    printf("Chiled with %d gets terminated with status %d \n",x,WEXITSTATUS(status));

    return 0 ;
}