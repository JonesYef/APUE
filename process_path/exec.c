#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

char*env_init[]={"USER=unknow","PATH=/tmp",NULL};

int main()
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork()");
        exit(1);
    }
    if(pid==0)
    {
        //execle 
        if(execle("/usr/bin/ls","ls","-lh",NULL,env_init)<0)
        {
            perror("execle()");
            exit(1);
        }
        exit(0);
    }
    wait(NULL);
    //execlp
    if(execlp("find","find","few.c",NULL)<0)
    {
        perror("execlp()");
        exit(1);
    }

    return 0;
}