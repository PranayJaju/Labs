#include "Heap.h"

int main() 
{
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        heapify(arr, i+1, i);
    }

    printf("Heapified array: ");
    print_array(arr, n);
}