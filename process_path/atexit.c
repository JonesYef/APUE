#include<stdlib.h>
#include<stdio.h>

static void myfun1()
{
    printf("this is first exit \n");
}
static void myfun2()
{

    printf("this is second exit \n");
}

int main()
{
    if(atexit(myfun1)!=0)
    {
        fprintf(stderr,"one at\n");
        exit(1);
    }
        if(atexit(myfun1)!=0)
    {
        fprintf(stderr,"one at\n");
        exit(1);
    }
        if(atexit(myfun2)!=0)
    {
        fprintf(stderr,"one at\n");
        exit(1);
    }
    return 0;
}

