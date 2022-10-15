#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#define NUM 4
//use lock unlock 
pthread_mutex_t mut[NUM];


static int ren(int n)
{
    if(n+1<NUM) return n+1;
    else return 0;
}
void * func(void *p)
{
    int n=(int)p;
    char ch='a'+n;
    while(1)
    {
        pthread_mutex_lock(mut+n);
        write(1,&ch,1);
        pthread_mutex_unlock(mut+ren(n));
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid[NUM];
    int err;
    for(int i=0;i<NUM;i++)
    {
        pthread_mutex_init(mut+i,NULL);//init mut
        pthread_mutex_lock(mut+i);//lock itself
        err=pthread_create(tid+i,NULL,func,(void *)i);
        if(err)
        {
            fprintf(stderr,"pthread_create failed: %s\n",strerror(err));
            exit(1);
        }
    }
    pthread_mutex_unlock(mut+0);// unlock the first one 
    alarm(3);
    for(int i=0;i<NUM;i++) pthread_join(tid[i],NULL);

    exit(0);
}