#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define N 256

int main(int argc,char * argv[])
{
    char name[N];
    char outname[N];
    FILE * fp1,*fp2;
    int ch;
    printf("Enter file name:");
    scanf("%255s",name);
    if((fp1=fopen(name,"r"))==NULL)
    {
        perror("error");
        exit(EXIT_FAILURE);
    }
    strcpy(outname,name);
    strcat(outname,".ne");
    fp2=fopen(outname,"w");
    while ((ch=getc(fp1))!=EOF)
    {
        ch=toupper(ch);
        putc(ch,fp2);
    }
    printf("Have Done\n");
    return 0;
}