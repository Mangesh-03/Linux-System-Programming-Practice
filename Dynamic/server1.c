#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
    void* handle = NULL;

    int(*fp)(int,int);      // not initialised bcz givs error/ warniing

    int iRet = 0;
    
    handle = dlopen("./libClient1.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unble to load a library\n");
        return -1;
    }

    printf("Library gets loaded sucessfully\n");

    fp = dlsym(handle,"Addition");

    if(fp == NULL)
    {
        printf("Unble to get address of function\n");
        dlclose(handle);
        return -1;
    }

    iRet = fp(11,10);
    printf("Addtion is :%d\n",iRet);

    fp = dlsym(handle,"Subtraction");

    if(fp == NULL)
    {
        printf("Unble to get address of function\n");
        dlclose(handle);
        return -1;
    }

    iRet = fp(11,10);
    printf("Subtraction is :%d\n",iRet);

    dlclose(handle);

    return 0;
}