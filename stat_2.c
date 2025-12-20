#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
    int iRet = 0;

    struct stat sobj;

    iRet = stat("Demo.txt",&sobj);

    printf("Inode Number : %lu\n",sobj.st_ino);
    printf("HardLink Count : %lu\n",sobj.st_nlink);
    printf("Total Size  : %lu\n",sobj.st_size);
    printf("Block Size : %lu\n",sobj.st_blksize);

    return 0;
}