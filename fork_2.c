#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid = 0;

    pid = fork();

    printf("PID of cuurent process : %d, PID of parent process : %d, Return of value : %d\n",getpid(),getppid(),pid);

    return 0;
}

