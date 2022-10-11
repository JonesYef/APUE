#include<stdio.h>
#include<stdlib.h>
#define SIZE 1024

int main()
{
    //fgetc fputc
    //fgets fputs
    //fread fwrite 
    FILE * fps,*fpd;
    char buf[SIZE];
    fps=fopen("test","r");
    fpd=fopen("one","w");
    if(fps==NULL)
    {
        perror("open");
        exit(1);
    }
    while (fread(buf,1,17,fps))
    {
        fwrite(buf,1,17,fpd);
    }
    fclose(fpd);
    fclose(fps);
    return 0;
}