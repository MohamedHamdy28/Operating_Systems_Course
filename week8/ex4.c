#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <string.h>
int main(){
    int *ptr;
    int size = 10*1024*1024;
    for(int i=0;i<10;i++)
    {
        ptr=malloc(size);
        memset(ptr,0,size);
        int who=RUSAGE_SELF;
        struct rusage u;
        getrusage(who,&u);
        printf("memory usage %d\n", u.ru_maxrss);
        sleep(1);
        free(ptr);
    }
}