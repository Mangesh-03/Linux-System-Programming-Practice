#include<stdio.h>

int main()
{
    char Arr[100] = {'\0'};

    fgets(Arr,sizeof(Arr),stdin);

    printf("Data recived : %s\n",Arr);

    return 0;
}