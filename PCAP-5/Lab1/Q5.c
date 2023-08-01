#include<stdio.h>
#include"mpi.h"

int fibonnaci(int n)
{
	if(n==1) return 0;
	if(n==2) return 1;
	return fibonnaci(n-1)+fibonnaci(n-2);
}

int factorial(int n)
{
	if(n==0) return 1;
	return n*factorial(n-1);
}

int main(int argc, char* argv[])
{
	int rank;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank%2==0) printf("Factorial of %d: %d\n", rank, factorial(rank));
	else printf("%d fibonnaci number is: %d\n", rank, fibonnaci(rank));

	MPI_Finalize();
}