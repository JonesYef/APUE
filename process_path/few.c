#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    puts("Being :");
    if((pid=fork())<0)
    {
        perror("fork()");
        exit(1);
    }
    if(pid==0)
    {
        execl("/usr/bin/ls","ls","-l",NULL);
        perror("execl");
        exit(1);
    }
    wait(NULL);
    puts("End over");
    return 0;
}