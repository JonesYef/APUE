#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdbool.h>
#define LEFT 100000
#define RIGHT 102000

int main()
{

    int i;
    for(i=LEFT;i<RIGHT;i++)
    {
        
        bool value=true;
        for(int j=2;j<i/2;j++)
        {
            if(i%j==0) {
                value=false;
                break;
            } 
        }
        if(value) 
        {
            printf("%d ",i);
        }
    }
    return 0;
}