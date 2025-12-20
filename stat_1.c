#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
    int iRet = 0;

    struct stat sobj;

    iRet = stat("Demo.txt",&sobj);

    if(iRet == 0)
    {
        printf("Stat works successfully\n");
    }
    else
    {
        printf("There is issue in stat\n");
        return -1;
    }

    return 0;
}