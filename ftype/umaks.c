#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)


int main()
{
    umask(0);
    if(creat("foo",RWRWRW)<0)
    {
        perror("creat:");
        exit(1);
    }
    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(creat("bar",RWRWRW)<0)
    {
        perror("creat2:");
        exit(1);
    }
    return 0;
}