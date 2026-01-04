#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    pid_t pid = 0;

    pid = fork();

    if(pid == 0)    // child
    {
        printf("Child process is runinng\n");
        printf("PID of child : %d & PPID of child : %d\n",getpid(),getppid());
        sleep(20);  //child state sleep
        printf("PID of child : %d & PPID of child : %d\n",getpid(),getppid());
        exit(0);

    }
    else            // parent
    {
        printf("Parent process running\n");
        printf("PID of parent : %d & PPID of parent : %d\n",getpid(),getppid());
        exit(1);
    }
    return 0;
}