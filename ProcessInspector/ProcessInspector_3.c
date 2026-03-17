#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int i = 0;

    printf("Command Line arguments are : \n");

    for(i = 0; i < argc; i++)
    {
        printf("Argument %d : %s\n",i+1,argv[i]);
    }

    return 0;
}