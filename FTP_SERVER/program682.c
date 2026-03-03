#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    pid_t pid = 0;

    pid = fork();

    // Create child has limit
    if(pid < 0)
    {
        printf("Unble  to create child process\n");
        return -1;
    }

    if(pid == 0)
    {
        printf("Child process get created sucessfully\n");
    }
    
    return 0;
}