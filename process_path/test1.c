#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
    int pid;
    int m=0;
    pid=fork();
    if(pid>0)
    {
        m++;
        printf("this is parent number : %d ,address : %p\n",m,&m);
        exit(0);
    }
    m--;
    printf("this is child vaild : %d, address : %p\n",m,&m);
    return 0;
}