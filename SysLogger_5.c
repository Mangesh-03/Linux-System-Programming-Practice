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

///////////////////////////////////////////////////////////////////////////////
//
//    Header file Inclusion
//
///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////
//
//    Global varible creation
//
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
//
//    Helper Functions Definations
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Function to collect CPU information
///////////////////////////////////////////////////////////////////////////////

static double cpu_percen()
{
    // logic to fetch cpu information
    return 0.0;
}

///////////////////////////////////////////////////////////////////////////////
// Function to collect memory(RAM) information
///////////////////////////////////////////////////////////////////////////////

static double mem_percen()
{
    // logic to fetch memory information
    return 0.0;
}

///////////////////////////////////////////////////////////////////////////////
// Function to collect disk information
///////////////////////////////////////////////////////////////////////////////

static double disk_percen(char * path)
{
    // logic to fetch disk information
    return 0.0;
}

// Thread proc for thread which collect system information
static void* collector_thread(void *arg) 
{
    double c = 0.0;
    double m = 0.0;
    double d = 0.0;

    (void)arg;
    printf("Inside collector thread\n");

    // Enter if ctrl+c is not arrived
    while(!stop_flag)
    {
        // calculate the current resource usage
        c = cpu_percen();
        m = mem_percen();
        d = disk_percen(disk_path);

        // start the critical section
        pthread_mutex_lock(&mtx);

        snap.cpu = c;
        snap.memory = m;
        snap.disk = d;

        // End of critical section
        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

// Thread proc for thread which writes log
static void* logger_thread(void *arg) 
{   
    (void)arg;
    printf("Inside logger thread\n");

    int fd = 0;
    double d = 0.0, c = 0.0, m = 0.0;

    fd = open("Marvellous_log.txt",O_CREAT | O_WRONLY | O_APPEND,0666);

    // if(fd == -1)
    // {
    //     perror("Error ");
    // }

    char welcome[] = "Marvellous System Logger";

    write(fd,welcome,strlen(welcome));

    while(!stop_flag)
    {
        pthread_mutex_lock(&mtx);

        d = snap.disk;
        c = snap.cpu;
        m = snap.memory;

        pthread_mutex_unlock(&mtx);

        // Write the information of structure snap into file
        // prepare the string  using sprintf
        char line[256];

        // write that string into log file

        //write(fd,line,size(line))

        //sleep for interval
        for(int i = 0; i < interval_sec && !stop_flag ; i++)
        {
            sleep(1);
        }
    }

    return NULL;
}


///////////////////////////////////////////////////////////////////////////////
//
//    Entry Point Function of project
//
///////////////////////////////////////////////////////////////////////////////

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

    // Thread to collect the information
    pthread_t t_collect;

    // Thread to write the data into log
    pthread_t t_log;

    // Create thread to collect information
    pthread_create(&t_collect,NULL,collector_thread,NULL);

    // Create thread to write data into log
    pthread_create(&t_log,NULL,logger_thread,NULL);

    // Main thread Waiting for child threads to terminate
    pthread_join(t_collect,NULL);
    pthread_join(t_log,NULL);

    printf("Terminating the Marvellous System Logger...\n");
    
    return 0;
}