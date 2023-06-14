#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter no.of integeres.\n");
	scanf("%d", &n);
	int arr[n];
	printf("Enter %d integers.\n", n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	int opcount=0; int swap=0;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			opcount++;
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swap++;
			}
		}
	}

	printf("Sorted array: ");
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\nOpCount: %d\nSwap: %d\n", opcount, swap);
}