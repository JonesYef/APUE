#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE * fp;
    char * line=NULL;
    size_t n=0;
    fp=fopen("test","r");
    if(fp==NULL)
    {
        perror("fopen");
        exit(1);
    }
    


    return 0;
}