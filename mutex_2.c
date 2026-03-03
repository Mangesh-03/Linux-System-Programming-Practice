#include<stdio.h>
#include<pthread.h>

// mutex object 
pthread_mutex_t lock;

int iCnt = 0;

void* Increment(void *args)
{
    pthread_mutex_lock(&lock);

        // Critical section start
        iCnt++;
        printf("%d\n",iCnt);
        // Critical section end

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t t1,t2;

    pthread_mutex_init(&lock,NULL);

    pthread_create(&t1,NULL,Increment,NULL);
    pthread_create(&t2,NULL,Increment,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}