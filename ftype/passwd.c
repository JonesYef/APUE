#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc,char * argv[])
{
    if(argc<2)
    {
        fprintf(stderr,"you shoule enter 2 arguments.");
        exit(1);
    }
    struct passwd * passline;
    passline=getpwnam(argv[1]);
    printf("%d",passline->pw_uid);
    return 0;
}