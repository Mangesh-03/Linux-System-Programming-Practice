#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void ShowProcessInformation(int pid)
{
    FILE *fp = NULL;

    char line[80];
    char FileName[100];

    sprintf(FileName,"/proc/%d/status",pid);
    printf("Accessing file : %s\n",FileName);

    fp = fopen(FileName,"r");

    if(fp == NULL)
    {
        printf("Unble to access system file\n");
        return;
    }

    printf("===================================================================\n");
    printf("---------------------Process Information---------------------------\n");
    printf("===================================================================\n");

    while(fgets(line,sizeof(line),fp) != NULL)
    {
        if(strncmp(line,"Name:",5) == 0    ||
           strncmp(line,"State:",6) == 0   ||
           strncmp(line,"Threads:",8) == 0 ||
           strncmp(line,"Pid:",4) == 0
        )
        {
            printf("%s\n",line);
        }
    }

    printf("===================================================================\n");
}

int main(int argc, char **argv , char **envp)
{
    int pid = 0;

    printf("===================================================================\n");
    printf("------------- -----Marvellous Process Inspector--------------------\n");
    printf("===================================================================\n");

    printf("Enter the PID of process that you want to inspect\n");
    scanf("%d",&pid);

    if(pid <= 0)
    {
        printf("Invalid pid\n");
        return -1;
    }

    ShowProcessInformation(pid);

    return 0;
}