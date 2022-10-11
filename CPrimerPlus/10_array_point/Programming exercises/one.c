#include<stdio.h>
#define YEARS 3
#define MONTHS 12
int main()
{
    const float rain[YEARS][MONTHS]=
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4}
    };
    const float (*yeas)[MONTHS],*months;
    float total;
    int index;
    for(yeas=rain,index=0;yeas!=&rain[3];index++,yeas++)
    {
        for(total=0.0,months=rain[index];months!=&rain[index][MONTHS];months++)
        {
            total+=(*months);
        }
        printf("%5d %15.1f\n",2010+index,total);
    }
    return 0;
}