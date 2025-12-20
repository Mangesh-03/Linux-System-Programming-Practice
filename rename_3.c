#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
    int iRet = 0;

    iRet = rename("./December.txt","./test/hello.txt");

    if(iRet == 0)
    {
        printf("rename succesful\n");
    }
    else
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    return 0;
}