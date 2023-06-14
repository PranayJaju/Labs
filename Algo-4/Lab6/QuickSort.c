#include<stdio.h>
#include<stdlib.h>

int opCount=0;

void swap(int a[], int i, int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

void QuickSort(int a[], int start, int end)
{
	if(end-start<=1) return;

    int pivot=a[start];
    int i=start+1, j=end-1;
    
    while(i<=j)
    {
        while(i<=j && a[j]>=pivot) 
        {
            j--;
            opCount++;
        }
        while(i<=j && a[i]<=pivot)
        {
            i++;
            opCount++;
        }
        
        if(i>=j) continue;
        swap(a, i, j);
    }
    swap(a, start, j);
    
    QuickSort(a, start, j);
    QuickSort(a, j+1, end);
}

int main()
{    
    int len;
    printf("Enter length of array: ");
    scanf("%d", &len);

    int a[len];
    printf("Enter elements: ");
    for(int i = 0; i < len; i++) scanf("%d", &a[i]);

    QuickSort(a, 0, len);
    for(int i = 0; i < len; i++) printf("%d ", a[i]);
    printf("\n");
    
    printf("OpCount = %d", opCount);

    return 0;
}