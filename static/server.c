#include<stdio.h>
#include<stdlib.h>

int Addition(int,int);
int Subtraction(int,int);

int main()
{
    int iRet = 0;

    iRet = Addition(11,10);
    printf("Addition is : %d\n",iRet);

    iRet = Subtraction(11,10);
    printf("Subtraction is : %d\n",iRet);

    return 0;
}


