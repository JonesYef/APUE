#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc,char*argv[] )
{
    // if(argc<2)
    // {
    //     fprintf(stderr,"you should enter 2 least aruments ..");
    //     exit(1);
    // }
    // FILE *fp;
    // if((fp=fopen(argv,"w"))<0)
    // {
    //     perror("fopen()");
    //     exit(1);
    // }
    const char * msg="hello this is printf\n";
    const char * msg1="hello this is fprintf\n";
    const char * msg2="hello this is write\n";
    printf("%s\n",msg);
    fprintf(stdout,"%s",msg1);
    write(1,msg2,19);
    fork();
    return 0;
}