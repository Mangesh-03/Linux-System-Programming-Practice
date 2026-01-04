#include<stdio.h>
#include<string.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>  
#include<unistd.h>

int main()
{
    int fd = 0;
    char *ptr = NULL;
    struct stat st;

    fd = open("Pune.txt",O_RDWR | O_CREAT ,0777);

    ftruncate(fd,4096);

    fstat(fd,&st);

    ptr = mmap(NULL,st.st_size,PROT_READ |PROT_WRITE, MAP_SHARED ,fd,0);

    strcpy(ptr,"Jay Ganesh");

    printf("Data from mapped memomery is : %s\n",ptr);

    munmap(ptr,4096);
    
    close(fd);

    return 0;
}