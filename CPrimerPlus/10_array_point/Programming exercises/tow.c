#include<stdio.h>
#define N 5


void print_arr(double arry[],int size)
{
    for(int i=0;i<size;i++)
        printf("%5.2lf ",arry[i]);
    printf("\n");
}
void copy_arr(double a[],double b[],int size)
{
    for(int i=0;i<size;i++)
    {
        a[i]=b[i];
    }
}

void copy_ptr(double *a,double *b,int size)
{
    for(int i=0;i<size;i++)
        *a++=*b++;
}
void copy_ptrs(double *a,double *b,double *c)
{
    while (b!=c)
    {
        *a++=*b++;
    }
    
}


int main()
{
    double sources[N]={1.1,2.2,3.3,4.4,5.5};
    double target1[N];
    double target2[N];
    double target3[N];
    copy_arr(target1,sources,N);
    print_arr(target1,N);
    copy_ptr(target2,sources,N);
    print_arr(target2,N);
    copy_ptrs(target3,sources,sources+N);
    print_arr(target2,N);

    return 0;
}