#include"two_head.h"
#include<stdio.h>

static int mode;
static double fuel;
static double distance; 

const char * kname="kilomiter";
const char * mname="miles";
const char * lname="liters";
const char * gname="gallons";

void get_info()
{
    if(mode==0)
    {
        printf("Enter distance travleled in %s:",kname);
        scanf("%lf",&distance);
        printf("Enter fule consumed in %s:",lname);
        scanf("%lf",&fuel);
    }
    else
    {
        printf("Enter distance travleled in %s:",mname);
        scanf("%lf",&distance);
        printf("Enter fule consumed in %s:",gname);
        scanf("%lf",&fuel);
    }
    
}
void show_info()
{
    if(mode==0) printf("fule consumption is %.1lf every 100km\n",fuel/(distance/100));
    else    printf("fule consumption in gallons: %.1lf\n",distance/fuel);
}
void set_mode(int n)
{
    if(n!=0&&n!=1) printf("invalid mode specified Mode(%d) used\n",mode);
    else mode=n;
}