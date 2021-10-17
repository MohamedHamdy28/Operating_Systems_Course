#include <stdio.h>
#include <stdint.h>


struct page{
    int name;
    uint8_t counter;
    int cycle;
};
int main(){
    int n,m,hit=0,miss=0;
    scanf("%d%d",&n,&m);
    struct page page_table[n];
    for(int i=0;i<n;i++)
    {
        page_table[i].name=0;
    }
    uint8_t refranced[n];
    int t,a;
    int index;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&t,&a);
        refranced[a]=1;
        int f=0;
        for (int i=0;i<n;i++)
        {
            if(page_table[i].name==a)
            {
                f=1;
                hit++;
                page_table[i].cycle=t;
                break;
            }
        }
        if(f==0)//miss
        {
            miss++;
            uint8_t mn=225;
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
                if(mn==page_table[i].counter&&page_table[i].name<page_table[index].name)
                {
                    mn=page_table[i].counter;
                    index=i;
                }
            }

            refranced[index]=0;
            page_table[index].name=a;
            page_table[index].counter=0;
            page_table[index].cycle=t;
        }
        for(int i=0; i<n; i++)
        {
            if(i==index)
                continue;
            page_table[i].counter = page_table[i].counter >> 1;
            page_table[i].counter = page_table[i].counter | (refranced[i] << 8);
        }
        printf("%d\n",f);
    }

    printf("%f\n", hit/(double)miss);
}
