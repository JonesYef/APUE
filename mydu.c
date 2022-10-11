#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
#include<dirent.h>
#define SIZE 1024
static unsigned long Isfile(const char * lpath)
{
    struct stat stat_str;
    if(lstat(lpath,&stat_str)<0)
    {
        perror("lstat2");
        exit(1);
    }
    return stat_str.st_blocks;
}

int main(int argc,char * argv[])
{

    // if(argc<2)
    // {
    //     fprintf(stderr,"you shuold enter two arguments least\n");
    //     exit(1);
    // }
    int64_t sum;
    int64_t sumdir;
    DIR *dir;
    for(int i=1;i<2;i++)
    {    
        struct stat stat_str;
        char * path="/home/jakc/mycode/ftype";
        // char * path=argv[i];
        if(lstat(path,&stat_str)<0)
        {
            perror("lstat1");
            exit(1);
        }
        if(!S_ISDIR(stat_str.st_mode))
        {   
            sum=stat_str.st_blocks;
            printf("%ld %10s\n",sum/2,path);
        }
        else
        {
            // aaa/dwadw/fefetgrg/
            dir=opendir(path);
            struct dirent * mydir;
            // strncat(path,"/*",SIZE);
            // printf("%s",path);
            while((mydir=readdir(dir))!=NULL) 
            {
                if(strcmp(mydir->d_name,".")==0||strcmp(mydir->d_name,"..")==0) continue;
                printf("%s\n",mydir->d_name);
                //printf("%lud\n",mydir->d_ino);
                char * catpath=path;
                strncat(catpath,mydir->d_name,SIZE);
                printf("%s\n",mydir->d_name);

                // sum=Isfile(name);
                // sumdir+=sum;
                // printf("%ld %10s\n",sum/2,mydir->d_name);
            }
            printf("%ld %10s\n",sumdir/2,path);
        }
        closedir(dir);

    }
    return 0;
}