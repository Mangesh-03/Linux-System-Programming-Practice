#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int iRet = 0,fd = 0;

    fd = open("Demo.txt",O_RDONLY);

    iRet = ftruncate(fd,5);

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