#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char **argv , char **envp)
{
    FILE *fp = NULL;
    char Buffer[256]= {'\0'};

    fp = fopen("/proc/meminfo","r");

    if(fp == NULL)
    {
        printf("Unble to open file\n");
        return -1;
    }

    printf("=========================================================================\n");
    printf("----------------------Marvellous memory scanner--------------------------\n");
    printf("=========================================================================\n");
    
    while(fgets(Buffer,sizeof(Buffer),fp) != NULL)
    {
        printf("%s\n",Buffer);
    }

    printf("=========================================================================\n");
    
    fclose(fp);
    return 0;
}