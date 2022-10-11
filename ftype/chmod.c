#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>


int main()
{

    struct stat statstr;
    if(stat("foo",&statstr)<0)
    {
        perror("stat:");
        exit(1);
    }
    if(chmod("foo",(statstr.st_mode& ~S_IXGRP)|S_ISGID)<0)
    {
        perror("chmod");
        exit(1);
    }
    if(chmod("bar",S_IRGRP|S_IWGRP)<0)
    {
        perror("chmod");
        exit(1);
    }
    
    return 0;
}