#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void*myRealloc(void*ptr,size_t newSize,size_t oldSize)
{
    if(ptr==NULL)
    {
        ptr= malloc(newSize);
    }
    if(newSize==0)
    {
        free(ptr);
        return NULL;
    }
    void* temp= malloc(newSize);
    size_t mn;
    if(oldSize<newSize)
    {
        mn=oldSize;
    } else{
        mn=newSize;
    }
    memcpy(temp,ptr,mn);
    free(ptr);
    return temp;
}

int main(){
    printf("Enter original array size: ");
    int n1 = 0;
    scanf("%d", &n1);
    int *a1 = malloc(n1 * sizeof(int));
    if(a1 == NULL)
    {
        printf("Error allocating memory!\n");
        return 1;
    }

    for(int i=0; i<n1; i++)
    {
        a1[i] = 100;
        printf("%d ", a1[i]);
    }

    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    a1 = myRealloc(a1, n2 * sizeof(int), n1 * sizeof(int));

    if(n2 > n1)
    {
        for(int i=n1; i<n2; i++)
            a1[i] = 0;
    }

    for(int i=0; i<n2; i++)
    {
        printf("%d ", a1[i]);
    }
    printf("\n");

    free(a1);
}