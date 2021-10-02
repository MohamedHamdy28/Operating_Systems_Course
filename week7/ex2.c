#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Enter the size of the array\n");
    int n;
    scanf("%d",&n);
    int *arr;
    arr=malloc(n*sizeof(int));
    if(arr == NULL) {
        printf("Error! memory not allocated.");
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        *(arr+i)=i;
    }
    for(int i=0;i<n;++i)
    {
        printf("%d\n",*(arr+i));
    }
    free(arr);
    return 0;
}


