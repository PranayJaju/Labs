#include <stdio.h>
#include <stdlib.h>

int opCount = 0;

int* Merge(int a[], int a_size, int b[], int b_size)
{
    int ai = 0, bi = 0;
    int len = a_size + b_size;
    int* c=(int*)calloc(len, sizeof(int));

    for(int i = 0; i < len; i++)
    {
        int c_ele;
        if (ai >= a_size) c_ele = b[bi++];
        else if (bi >= b_size) c_ele = a[ai++];
        else c_ele = a[ai] > b[bi] ? b[bi++] : a[ai++] ;

        c[i] = c_ele;
        opCount++;
    }
    return c;
}

int * MergeSort(int a[], int len)
{

    if(len==1) return a;

    int len_l=len-len/2, len_r=len/2;
    int li=0, ri=0;

    int* l=(int*)malloc(len_l*sizeof(int));
    int* r=(int*)malloc(len_r*sizeof(int));

    for(int i=0; i<len; i++)
    {
        if (i<=(len-1)/2) l[li++]=a[i];
        else r[ri++]=a[i];
    }

    l=MergeSort(l, len_l);
    r=MergeSort(r, len_r);

    return Merge(l, len_l, r, len_r);
}

int main()
{
    int len;
    printf("Enter length of array: ");
    scanf("%d", &len);

    int a[len];
    printf("Enter elements: ");
    for(int i=0; i<len; i++) scanf("%d", &a[i]);

    int *b=MergeSort(a, len);
    printf("Sorted array: ");
    for(int i=0; i<len; i++) printf("%d ", b[i]);
    printf("\n");

    printf("OpCount = %d", opCount);

    return 0;
}