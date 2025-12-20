#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
    int iRet = 0;
    iRet  = link("./Demo.txt","./test/Demo.txt");

    if(iRet == 0)
    {
        printf("link is successful\n");
    }

    else
    {
        printf("unsucess\n");
    }
    return 0;
}