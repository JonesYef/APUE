#include<stdio.h>

static int units=0;


void critic();

int main()
{
    printf("how many ------\n");
    scanf("%d",&units);
    while (units!=56) critic();
    printf("you must have looked it up\n");
    return 0;
}
void  critic()
{
    printf("NO luck my friend try to again .\n");
    scanf("%d",&units);
}