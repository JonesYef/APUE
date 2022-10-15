#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#define NUM 4
//use lock unlock 
pthread_mutex_t mut=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
static int num=0;
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
        pthread_mutex_lock(&mut);
        if(num!=n) pthread_cond_wait(&cond,&mut);
        write(1,&ch,1);
        num=ren(n);
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mut);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid[NUM];
    int err;
    for(int i=0;i<NUM;i++)
    {
        //pthread_mutex_init(&mut,NULL);//init mut
        //pthread_mutex_lock(&mut);//lock itself
        err=pthread_create(tid+i,NULL,func,(void *)i);
        if(err)
        {
            fprintf(stderr,"pthread_create failed: %s\n",strerror(err));
            exit(1);
        }
    }
    //pthread_mutex_unlock(&mut);// unlock the first one 
    alarm(3);
    for(int i=0;i<NUM;i++) pthread_join(tid[i],NULL);
    pthread_mutex_destroy(&mut);
    pthread_cond_destroy(&cond);
    exit(0);
}