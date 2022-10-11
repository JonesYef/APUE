#include<stdio.h>
#include<stdlib.h>
int * make_array(int size,int val)
{
    
    int * p=(int *)malloc(size*sizeof(int));
    for(int i=0;i<size;i++) p[i]=val;
    return p;
}

void show_array(const int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        if(i%8==0) printf("\n");
        printf("%d ",array[i]);
    }    
    printf("\n");
}

int main()
{
    int *pa;
    int size;
    int value;
    printf("Enter the number of elements:");
    while (scanf("%d",&size)==1&&size>0)
    {
        printf("Enter the initalization value:");
        scanf("%d",&value);
        pa=make_array(size,value);
        if(pa)
        {
            show_array(pa,size);
            free(pa);
        }
        printf("Enter the number of elements (-1 quit):");
    }
    return 0;
}