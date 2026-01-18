#include<stdio.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<string.h>

#define MAXTEXT 512

struct MarvellousMsg
{
    long int msg_type;
    char data[MAXTEXT];
};
int main()
{
    key_t key; 
    int id = 0,iRet = 0;

    struct MarvellousMsg mobj;

    key = ftok(".",'a');

    id = msgget(key,0666);

    if(id == -1)
    {
        printf("Unble to allocate msg queue\n");
        return -1;
    }
        
    iRet = msgrcv(id,(void *)&mobj,MAXTEXT,11,IPC_NOWAIT);

    if(iRet > 0)
    {
        printf("Data recived from msg queue : %s\n",mobj.data);
    }

    return 0;
}