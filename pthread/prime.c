#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
// use prime number prthread
#define LEFT 200000
#define RIGHT 200100
#define THRNUM 101

static void * the_prim(void * );


int main()
{
    pthread_t tid[THRNUM];
    int err;
    for(int i=LEFT;i<=RIGHT;i++)
    {
        err=pthread_create(tid+(i-LEFT),NULL,the_prim,&i);
        if(err)
        {
            fprintf(stderr,"pthread_create failed:%s\n",strerror(err));
            exit(1);
        }
    }
    for(int i=LEFT;i<=RIGHT;i++)
    {
        pthread_join(tid[i-LEFT],NULL);
    }
    exit(0);
}


static void * the_prim(void * p)
{
    int mark;
    int i=*(int *)p;
    mark=1;
    for(int j=2;j<i/2;j++)
    {
        if(i%j==0)
        {
            mark=0;
            break;
        }
    }
    if(mark) printf("prime: %d\n",i);
    pthread_exit(NULL);

}

