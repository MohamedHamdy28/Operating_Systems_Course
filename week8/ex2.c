#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <string.h>
int main(){
    char* ptr;
    int size = 1000*1024*1024; // when I allocate just 10MB it takes longer for the si and so values to change, so I increased the amount of allocated memory to make it faster
    for(int i=0;i<10;i++)
    {
        ptr= malloc(size);
        memset(ptr,0,size);
        sleep(1);
        printf("Run %d\n",i);
        //free(ptr);
    }
    /*
     * my findings: at the very beginning the values of si and so are 60 and 182 respectively then the value of si keeps fluctuating, sometimes it reaches 0
     * however the values of so stays 0
    */
}
