#include<stdio.h>
#include"mpi.h"

int isPrime(int n)
{
	if(n==1) return 0;

	int c=0;
	for(int i=2; i<n; i++)
		if(n%i==0)
			c++;

	if(c>0) return 0;
	else return 1;
}

int main(int argc, char* argv[])
{
	int rank;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(isPrime(rank+1)) printf("%d is prime\n", rank+1);

	MPI_Finalize();
}