#include <stdio.h>
#include <stdint.h>




struct page
{
    int id;
    uint8_t cnt;
};

int main(int argc, char** argv)
{
    int n = 100;
    uint8_t refranced[1001];

    sscanf(argv[1], "%d", &n);

    FILE* fp = fopen("ex1.txt", "r");

    struct page page_table[n];
    for(int i=0;i<n;i++) page_table[i].id=0;

    int hit=0, miss=0, id;

    while(fscanf(fp, "%d", &id) != EOF)
    {
        refranced[id] = 1;

        int f=0;
        for(int i=0; i<n; i++)
        {
            if(page_table[i].id == id)
            {
                f = 1;
                break;
            }
        }

        if(f)
        {
            hit++;
        }
        else
        {
            miss++;
            uint8_t mn = 255;
            int index;
            for(int i=0; i<n; i++)
            {
                if(page_table[i].id == 0)
                {
                    index = i;
                    break;
                }
                if(page_table[i].cnt < mn)
                {
                    mn = page_table[i].cnt;
                    index = i;
                }
            }

            refranced[index] = 0;
            page_table[index].id = id;
            page_table[index].cnt = 0;
        }


        for(int i=0; i<n; i++)
        {
            page_table[i].cnt = page_table[i].cnt >> 1;
            page_table[i].cnt = page_table[i].cnt | (refranced[i] << 8);
        }

    }

    printf("Hits: %d, Misses: %d\n", hit, miss);
    printf("Hits/Misses = %f\n", hit/(double)miss);
}