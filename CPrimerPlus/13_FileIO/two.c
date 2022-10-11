#include<stdio.h>
#include<stdlib.h>

int main(int argc,char * argv[])
{
    int ch;
    FILE * fp1,*fp2;
    if(argc<3)
    {
        printf("Missing file,need sources and target file\n");
        exit(EXIT_FAILURE);
    }
    if((fp1=fopen(argv[1],"rb"))==NULL)
    {
        perror("error");
        exit(EXIT_FAILURE);
    }
    fp2=fopen(argv[2],"wb");
    while ((ch=getc(fp1))!=EOF)
    {
        putc(ch,fp2);
    }
    printf("process Done");
    return 0;
}
