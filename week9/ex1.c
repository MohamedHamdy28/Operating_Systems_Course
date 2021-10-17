#include<stdio.h>
#include <stdint.h>

struct page_frame_container{
    int name;
    unit8_t counter;
};
void accessed(struct& page)
{

}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    struct page_frame_container page_frames[n];
    int hit=0,miss=0;

    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        int t,a,h=0;
        scanf("%d%d",&t,&a);
        for(int i=0;i<n;i++)
        {
            if(page_frames[i].num==a)
            {
                hit++;
                h=1;
                accessed(page_frames[i]);
            }
        }
        if(h==0)//miss
        {
            miss++;
            unit8_t mn=225;
            int index;
            for(int i=0;i<n;i++)
            {
                if(mn>page_frames[i].counter)
                {
                    mn=page_frames[i].counter;
                    index=i;
                }
            }
            page_frames[index].counter=0;
            page_frames[index].name=a;
        }
        for(int i=0; i<n; i++)
        {
            page_frames[i].counter = page_frames[i].counter >> 1;
            if (h==0)
            {
                page_frames[i].counter = page_frames[i].counter | (0 << 8);
            }
            else
            {
                page_frames[i].counter = page_frames[i].counter | (1 << 8);
            }

        }
    }
    printf("Hits: %d, Misses: %d\n", hit, miss);
    printf("Hits/Misses = %f\n", hit/(double)miss);
}
