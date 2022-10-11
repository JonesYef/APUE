#include<stdio.h>
#include "two_head.h"
int main()
{
    int mode;
    printf("enter 0 for metric mode , 1 for us mode:");
    scanf("%d",&mode);
    while(mode>=0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("enter 0 for metric mode , 1 for us mode\n");
        printf("(-1 to quit):");
        scanf("%d",&mode);
    }
    printf("Done .\n");
    return 0;
}