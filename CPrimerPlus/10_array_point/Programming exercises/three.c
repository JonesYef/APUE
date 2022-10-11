#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define N 6
int ReMax(int array[],int size)
{
    int res=INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(res<array[i]) res=array[i];
    }
    return res;
}
int ReMaxIndex(double array[],int size)
{
    int index;
    double res=__DBL_MIN__;
    for(int i=0;i<size;i++)
    {
        if(res<array[i]) 
        {
            res=array[i];
            index=i;
        }
    }
    return index;
}
double ReDifVal(double array[],int size)
{
    double ma=__DBL_MIN__;
    double mi=__DBL_MAX__;
    for(int i=0;i<size;i++)
    {
        if(mi>array[i]) mi=array[i];
        if(ma<array[i]) ma=array[i];
    }
    return ma-mi;
}

void mysort(double array[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            if(array[i]<array[j])
            {
                double temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }

}

void copy_array(double array[],double source[],double * end)
{

    while(source!=end)
    {
        *array++=*source++;
    }
}

void printarray(double array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%5.1lf ",array[i]);
    }
}

void copy_print(int n,int m,double array[n][m],double soruce[n][m])
{
    int index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            array[i][j]=soruce[i][j];
            printf("%5.1lf ",array[i][j]);
        }
    }
}



int main()
{
    double test[N]={1.3,5.6,8.9,2.3,4.5,1.3};
    mysort(test,N);
    //printarray(test,N);
    double target[2][4];
    double test2[2][4]={{1,5,6,9},{1,7,9,6}};
    copy_print(2,4,target,test2);
    return 0;
}