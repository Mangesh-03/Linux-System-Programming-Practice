#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("PID of running process : %ld\n",getpid());
    printf("Parent PID : %ld\n",getppid());

    return 0;
}