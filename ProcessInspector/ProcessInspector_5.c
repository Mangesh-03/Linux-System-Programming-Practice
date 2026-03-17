#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char **argv , char **envp)
{
    printf("List of environment variables : \n");

    for(int i = 0; envp[i] != NULL; i++)
    {
        printf("Environment variable %d : %s\n",i+1,envp[i]);
    }

    return 0;
}