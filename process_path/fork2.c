#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdbool.h>
#define LEFT 100000
#define RIGHT 100200

int main()
{

    int i;
    pid_t pid;
    for(i=LEFT;i<RIGHT;i++)
    {
        pid=fork();
        if(pid==0)
        {
            bool value=true;
            for(int j=2;j<i/2;j++)
            {
                if(i%j==0) {
                    value=false;
                    break;
                } 
            }
            if(value) printf("%d ",i);
            sleep(1000);
            exit(0);
        }
    }
    return 0;
}