#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char **argv , char **envp)
{
    setenv("LANGUAGE","C Programming",1);
    printf("Language is : %s\n",getenv("LANGUAGE"));
    
    return 0;
}