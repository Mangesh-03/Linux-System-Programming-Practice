#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("Inside my process with PID : %d\n",getpid());
    
    while(1)
    {}

    return 0;
}