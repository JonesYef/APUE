#include <stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>


char buf1[]="abcdefghij";
char buf2[]="ABCDEFGHIJ";

int main()
{
    int fd;
    if((fd=creat("file.hole",741))<0)
    {
        perror("creat :");
        exit(1);
    }
    if(write(fd,buf1,10)!=10)
    {
        perror("wirte:");
        exit(1);
    }
    if(lseek(fd,16384,SEEK_CUR)==-1)
    {
        perror("lseek :");
        exit(1);
    }
    if(write(fd,buf2,10)!=10)
    {
        perror("2 wirte :");
        exit(1);
    }
    close(fd);
    return 0;
}