#include<stdio.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<sys/ipc.h>

int main()
{
    key_t key;
    int id = 0;

    key = ftok(".",'a');

    id = msgget(key,0666);

    if(id == -1)
    {
        printf("Unble to allocate msg queue\n");
        return -1;
    }
    
    return 0;
}