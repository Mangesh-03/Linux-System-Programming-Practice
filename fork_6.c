#include<stdio.h>
#include<unistd.h>

int main()
{
    if(fork() == 0)
    {
        printf("Child process scheduled\n"); 
    }
    else
    {
        printf("parent process svheduled\n");
    }
    

    return 0;
}

