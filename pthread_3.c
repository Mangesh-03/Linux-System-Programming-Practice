#include<stdio.h>
#include<pthread.h>

void * Demo(void * p)
{
    printf("Inside thread\n");
    
    return NULL;
}

int main()
{
    pthread_t TID;
    int iRet = 0;

    printf("main thread started\n");

    iRet = pthread_create(
                            &TID,       // Thread ID
                            NULL,       // Thread Attribute
                            Demo,       // Thread callback function
                            NULL        // parametr for Thread callback function
    );

    if(iRet == 0)
    {
        printf("Thread gets creat successfully\n");
    }

    // wait

    printf("End of main thread\n");
    return 0;
}