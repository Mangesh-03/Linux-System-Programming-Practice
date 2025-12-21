#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd = 0;
    off_t offset = 0;
    char Buffer[100];

    fd = open("./LSP.txt",O_RDONLY);

    offset = lseek(fd,0,SEEK_SET);

    printf("Curent ofset is : %ld\n",offset);

    read(fd,Buffer,10);

    offset = lseek(fd,0,SEEK_CUR);

    printf("Curent ofset is : %ld\n",offset);


    return 0;
}