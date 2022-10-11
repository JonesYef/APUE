#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// use fseek dispaly strlenth
int main()
{
    FILE * fp;
    fp=fopen("test","r");
    if(fp==NULL)
    {
        perror("open");
        exit(1);
    }
    fprintf(stdout,"%d\n",fseek(fp,-50,SEEK_END));
    printf("%ld\n",ftell(fp));
    fclose(fp);
    return 0;
}