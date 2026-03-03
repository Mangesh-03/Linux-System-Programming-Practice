#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int iRet = 0;

    iRet = fork();

    if(iRet == 0)
    {
        printf("Child with pid : %d\n",getpid());
    }
    else
    {
        printf("Parent process with pid: %d\n",getpid());
        printf("Child pid : %d\n",iRet);
    }

    return 0;
}