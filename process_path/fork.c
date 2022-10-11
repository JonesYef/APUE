#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


int main()
{
    pid_t pid;
    printf("Begin pid[%d]\n",getpid());
    //use fork creat son fork 
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    if(pid==0)//child process 
    {
        printf("child process pid[%d]\n",getpid());
    }
    else printf("parent process pid[%d]\n",getpid());
    printf("this is End \n");
    return 0;
}
