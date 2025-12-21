#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    int iRet = 0;

    struct stat sobj;

    iRet = stat(argv[1],&sobj);

    printf("Inode Number : %lu\n",sobj.st_ino);
    printf("HardLink Count : %lu\n",sobj.st_nlink);
    printf("Total Size  : %lu\n",sobj.st_size);
    printf("Block Size : %lu\n",sobj.st_blksize);

    printf("File Type is : %d\n",sobj.st_mode);

    if(S_ISBLK(sobj.st_mode))
    {
        printf("Block Device\n");
    }
    else if(S_ISCHR(sobj.st_mode))
    {
        printf("Character device\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Directory File\n");
    }
    else if(S_ISREG(sobj.st_mode))
    {
        printf("Regular file\n");
    }
    else if(S_ISSOCK(sobj.st_mode))
    {
        printf("Socket file\n");
    }
    else if(S_ISFIFO(sobj.st_mode))
    {
        printf("Pipe file\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Symbolic link\n");
    }

    return 0;
}