#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t childPid = 0,ret = 0;
    int status = 0;

    childPid = fork();

    if(childPid == 0)
    {
        printf("Child is running... with PID  : %d\n",getpid());
        sleep(10);
        printf("Child exiting...\n");
        exit(11);

    }
    else
    {
        printf("Parent is runing...\n");

        printf("Parent is waiting for child : %d\n",childPid);

        ret = waitpid(childPid,&status,0);

        if(WIFEXITED(status))
        {
            printf("Child exited with PID : %d\n",ret);
            printf("Exit status of child is : %d\n",WEXITSTATUS(status));
        }
    }

    return 0;
}