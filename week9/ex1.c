#include <stdio.h>
#include <stdint.h>

struct page{
    int name;
    unsigned int counter;
};
int main(int argc, char** argv){
    int n,hit=0,miss=0;
    if(argc > 2)
    {
        printf("Wrong number of arguments\n");
        return 1;
    }
    sscanf(argv[1], "%d", &n);
    FILE* fp = fopen("ex1.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    struct page page_table[n];
    for(int i=0;i<n;i++)
    {
        page_table[i].name=0;
    }
    int refranced[n];
    for(int i=0;i<n;i++)
    {
        refranced[i]=0;
    }
    int a;
    int index;
    while (fscanf(fp,"%d",&a)!=EOF)
    {
        refranced[a-1]=1;
        int f=0;
        for (int i=0;i<n;i++)
        {
            if(page_table[i].name==a)
            {
                f=1;
                hit++;
                break;
            }
        }
        if(f==0)//miss
        {
            miss++;
            uint8_t mn = 255;
            for(int i=0;i<n;i++)
            {
                if(page_table[i].name==0)
                {
                    index=i;
                    break;
                }
                if(mn>page_table[i].counter)
                {
                    mn=page_table[i].counter;
                    index=i;
                }
                else if(mn==page_table[i].counter&&page_table[i].name<page_table[index].name)
                {
                    mn=page_table[i].counter;
                    index=i;
                }
            }

            refranced[a-1]=0;
            page_table[index].name=a;
            page_table[index].counter=0;
        }
        for(int i=0; i<n; i++)
        {
            page_table[i].counter = page_table[i].counter >> 1;
            page_table[i].counter = page_table[i].counter | (refranced[i] << 7);
        }
        printf("%d\n",f);
    }

    printf("Hits: %d, Misses: %d\n", hit, miss);
    printf("Hits/Misses = %f\n", hit/(double)miss);
}