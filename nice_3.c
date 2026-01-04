#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main()
{
    int iRet = 0;

    iRet = nice(0);

    printf("Current nice value is : %d\n",iRet);
    
    iRet = nice(-5); // Increase priority

    printf("Current nice value is : %d\n",iRet);

    if(iRet == -1)
    {
        printf("%s\n",strerror(errno));
    }
    return 0;
}