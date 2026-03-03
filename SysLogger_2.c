/*
     argv[0]
     argc = 1
    ./myexe

     argv[0]     argv[1]
     argc = 2
     ./myexe     /home/Desktop/Demo

     argv[0]     argv[1]                argv[2]
     argc = 3
     ./myexe     /home/Desktop/Demo      5
*/

#define _GNU_SOURCE

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<signal.h>
#include<fcntl.h>
#include<time.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/statvfs.h>

static volatile sig_atomic_t stop_flag = 0;

// ctrl+c handler
static void sigint_handler(int sig)
{
    (void)sig;
    
    printf("Marvellous System logger is terminating ....\n");

    // Tell the thread to stop the execution
    stop_flag = 1;
}

// structure which holds all system information
typedef struct
{
    double cpu;                // CPU  usage percentage
    double memory;             // RAM usage  percentage
    double disk;               // Hard Disk uasage percentage                
}Snapshot;

// Global object which holds information
static Snapshot snap;

// mutex lock for critical section
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

// Default path for disk
static char* disk_path = "/";

// Sleep timer for log
static int interval_sec = 2;

int main(int argc, char **argv)
{
    // ./myexe /home/Desktop/Demo
    if(argc == 2)
    {   
        disk_path = argv[1];
    }
    // ./myexe   /home/Desktop/Demo     5
    else if(argc == 3)
    {
        interval_sec = atoi(argv[2]);
    }
    printf("Marvellous System logger\n");

    printf("Path is  : %s\n",disk_path);
    printf("Interval is : %d\n",interval_sec);

    // structure for handling ctrl+c
    struct sigaction sa;

    memset(&sa,0,sizeof(sa));

    sa.sa_handler = sigint_handler;

    sigaction(SIGINT,&sa,NULL);

    while(1)
    {
        sleep(1);
    }
    
    
    return 0;
}