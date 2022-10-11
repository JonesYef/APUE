#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char * argv[])
{

    int i;
    char ** ptr;
    extern char ** __environ;
    for(i=0;i<argc;i++)
    {
        printf("argv[%d]: %s\n",i,argv[i]);
    }
    for(ptr=__environ;*ptr!=0;ptr++)
    {
        printf("%s\n",*ptr);
    }
    exit(0);

}