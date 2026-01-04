#include<stdio.h>
#include<unistd.h>

int main()
{
    int iRet = 0;

    iRet = nice(0);

    printf("Current nice value is : %d\n",iRet);

    return 0;
}