#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid = 0;

    pid = fork();

    if(pid == 0)
    {
        printf("Child says : PID of cuurent process : %d, PID of parent process : %d, Return of value : %d\n",getpid(),getppid(),pid);
        execl("./Firstexe","",NULL);
    }
    else
    {
        printf("Parent says : PID of cuurent process : %d, PID of parent process : %d, Return of value : %d\n",getpid(),getppid(),pid);
    }

    return 0;
}

// process 
// pprt ->per process
// rt ->region table