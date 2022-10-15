#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>


static void * func1(void  * val)
{
    puts(val);
    //return NULL;
}

static void * func(void * test)
{
    puts("this is thread begin ..\n");
    pthread_cleanup_push(func1,"1");
    pthread_cleanup_push(func1,"2");
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);
    pthread_exit(NULL);
}



int main()
{
    puts("begin ...\n");
    pthread_t tid;
    int err;
    err=pthread_create(&tid,NULL,func,NULL);
    if(err)
    {
        fprintf(stderr,"pthread is failed :%s\n",strerror(err));
        exit(1);
    }
    pthread_join(tid,NULL);
    puts("end of ...\n");
    exit(0);
}