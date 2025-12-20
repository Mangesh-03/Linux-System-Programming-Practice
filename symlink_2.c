#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>

int main()
{
    int iRet = 0;
    
    iRet  = symlink("./LSP.txt","./test/LSPl.txt");

    if(iRet == 0)
    {
        printf("symlink is successful\n");
    }

    else
    {
        printf("%s\n",strerror(errno));
    }
    return 0;
}