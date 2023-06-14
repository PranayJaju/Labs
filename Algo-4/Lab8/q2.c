#include "Heap.h"

void heap_sort(int arr[], int n) 
{
    create_heap(arr, n);

    for (int i = n - 1; i > 0; i--) 
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        create_heap(arr, i);
    }
}

int main() 
{
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heap_sort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);
}