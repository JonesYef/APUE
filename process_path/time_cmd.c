#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#include<getopt.h>
#define SIZE 256

int main(int argc,char * argv[])
{
    time_t m_time;
    time(&m_time);
    struct tm *m_tm;
    m_tm=localtime(&m_time);
    // FILE *fp;
    // if((fp=fopen("newout","a+"))==NULL)
    // {
    //     perror("fopen()");
    //     exit(1);
    // }
    //printf("%d %d %d %d",m_tm->tm_year+1900,m_tm->tm_mon+1,m_tm->tm_mday,m_tm->tm_hour);
    // char s[SIZE];
    //size_t count;
    // while (1)
    // {
    //     strftime(s,SIZE,"%Y-%m-%d-%H:%M:%S\n",m_tm);
    //     m_time=mktime(m_tm);
    //     m_tm=localtime(&m_time);
    //     fputs(s,fp);
    //     fflush(fp);
    //     sleep(1);
    // }
    char s[SIZE];   
    int ch;
    char fomat[SIZE];
    fomat[0]='\0';
    FILE* fp=stdout;
    while ((ch=getopt(argc,argv,"-Ymdh:"))!=-1)
    {
        //file direct
        switch (ch)
        {
        case 1:
            fp=fopen(argv[optind-1],"a+");
            if(fp==NULL)
            {
                perror("fopen()");
                fp=stdout;
            }
        break;
        case 'Y':
            strncat(fomat,"%Y-",10);
            break;
        case 'm':
            strncat(fomat,"%m-",10);
            break;
        case 'd':
            strncat(fomat,"%d-",10);
            break;
        case 'h':
            if(strcmp("12",optarg)==0)
                strncat(fomat,"%I(%p)",10);
            else if(strcmp("24",optarg)==0)
                strncat(fomat,"%H(%p)",10);
            else fprintf(stderr,"option -h is invalid");
            break;
        default:
            printf("?? getopt returned character code 0%o ??\n", ch);
            break;
        }

    }
    strncat(fomat,"\n",3);
    strftime(s,SIZE,fomat,m_tm);
    fputs(s,fp);
    return 0;
}