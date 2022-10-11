#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
char buf[1024];

int main()
{
    int n=10;
    int readsize;
    int fd;//file decrite
    if((fd=open("test",O_RDWR|O_APPEND))==-1)
    {
        perror("open ");
        exit(1);
    }
    if(lseek(fd,10,SEEK_SET)==-1)
    {
        perror("lseek");
        exit(1);
    }
    if((readsize=read(fd,buf,n))>0)
    {
        if(write(fd,buf,n)!=readsize)
        {    
            perror("wirte ");
            exit(1);
        }
    }
    if(write(fd,buf,5)==-1)
    {
        perror("2 wirte");
        exit(1);
    }

    for(int i=0;i<10;i++)
    {
        printf("%c",buf[i]);
    }
    

    close(fd);
    return 0;
}
