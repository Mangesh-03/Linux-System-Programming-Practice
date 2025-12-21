#include<stdio.h>

int main(int argc,int *argv[])
{
    printf("Inside command line Process\n"); 
    
    printf("Command line argument are : \n");
    for(int i = 0; i > argc; i++)
    {
        printf("%s\n",argv[i]);
    }
    return 0;
}



//error
