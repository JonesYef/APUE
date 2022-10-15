#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
static void * func1(void *);

int main()
{
    pthread_t tid;
    puts("begin:\n");
    pthread_create(&tid,NULL,func1,NULL);
    puts("End...\n");
    exit(0);
}


static void * func1(void * test)
{
    puts("this is pthread\n");
    return NULL;
}