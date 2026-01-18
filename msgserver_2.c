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

    id = msgget(key,0666 | IPC_CREAT);

    if(id == -1)
    {
        printf("Unble to allocate msg queue\n");
        return -1;
    }

    mobj.msg_type = 11;

    strcpy(mobj.data,"Jay Ganesh...");
        
    iRet = msgsnd(id,(void *)&mobj,MAXTEXT,0);

    if(iRet == 0)
    {
        printf("Message sent successfully\n");
    }

    return 0;
}