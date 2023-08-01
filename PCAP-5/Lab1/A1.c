#include<stdio.h>
#include"mpi.h"

int reverse(int n)
{
	int rev=0;
	while(n>0)
	{
		int r=n%10;
		n/=10;
		rev=rev*10+r;
	}
	return rev;
}

int main(int argc, char* argv[])
{
	int rank;
	int arr[]={18, 523, 301, 1234, 2, 14, 108, 150, 1928};

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	printf("%d: ", arr[rank]);
	arr[rank] = reverse(arr[rank]);
	for(int i=0; i<9; i++)
		printf("%d, ",arr[i]);
	printf("\n\n");

	MPI_Finalize();
}