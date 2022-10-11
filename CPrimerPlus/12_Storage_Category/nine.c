#include<stdio.h>
#include<stdlib.h>

int main()
{

    int num;
    printf("How many words do you wish to enter?:");
    scanf("%d",&num);
    printf("Enter %d words now",num);
    char**p=(char *) malloc(num*sizeof(char *));
    free(p);
    return 0;
}