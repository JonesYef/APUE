#include<stdio.h>
#include<string.h>
#define N 100



int x=3;
char * getwords()
{ 
    static char array[N];
    fgets(array,N,stdin);
    return array;
}



int main()
{
    printf("%s\n",getwords());
    
    return 0;
}