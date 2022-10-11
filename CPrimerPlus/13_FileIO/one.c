#include<stdio.h>
#include<stdlib.h>
#define N 256

int main()
{
    int ch;
    FILE * fp;
    unsigned long count=0;
    char name[N];
    printf("Enter your file name:");
    if(scanf("%s",name)!=1) 
    {
        printf("Fail to scanf \n");
        exit(EXIT_FAILURE);
    }
    if((fp=fopen(name,"r"))==NULL)
    {
        perror("error ");
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    printf("the file %s has %lu character \n",name,count);
    return 0;
}