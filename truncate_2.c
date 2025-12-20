#include<stdio.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    iRet = truncate("Demo.txt",30);

    if(iRet == 0)
    {
        printf("Truncate is sucessful\n");

    }
    else
    {
        printf("unsucess\n");
    }
    return 0;
}






// second option for make hole in the file