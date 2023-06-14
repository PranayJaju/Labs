#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[], int n, int i) 
{
    int parent = (i - 1) / 2;
    if (parent >= 0 && arr[parent] < arr[i]) 
    {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        heapify(arr, n, parent);
    }
}

void create_heap(int arr[], int n) 
{
    for (int i = 1; i < n; i++)
        heapify(arr, n, i);
}

void print_array(int arr[], int n) 
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}