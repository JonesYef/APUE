#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>

#define NUM 1024
#define FMANE "./test" 
pthread_mutex_t mut=PTHREAD_MUTEX_INITIALIZER;

void * func(void * p)
{
    char str[NUM];
    FILE * fp;
    if((fp=fopen(FMANE,"r+"))==NULL)
    {
        perror("fopen is failed:");
        exit(1);
    }
    pthread_mutex_lock(&mut);
    fgets(str,NUM,fp);
    fseek(fp,0,SEEK_SET);
    fprintf(fp,"%d\n",atoi(str)+1);
    fclose(fp);
    pthread_mutex_unlock(&mut);
    pthread_exit(NULL);
}

int main()
{
    //file fopen fclose  add 1 -> 20
    pthread_t tid[NUM];
    int err;
    for(int i=0;i<20;i++)
    {
        err=pthread_create(tid+i,NULL,func,NULL);
        if(err)
        {
            fprintf(stderr,"pthread_create failed : %s\n",strerror(err));
            exit(1);
        }
    }
    for(int i=0;i<20;i++) pthread_join(tid[i],NULL);
    pthread_mutex_destroy(&mut);
    exit(0);
}