#include<stdio.h>

int main(int argc, char *argv[])
{
    printf("Number of command line argument : %d\n",argc);

    printf("Executable : %s\n",argv[0]);
    printf("IP address: %s\n",argv[1]);
    printf("Port number: %s\n",argv[2]);
    printf("Targeted file : %s\n",argv[3]);
    printf("New File name : %s\n",argv[4]);
    return 0;
}