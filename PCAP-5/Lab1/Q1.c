#include<stdio.h>
#include<math.h>
#include"mpi.h"

int main(int argc, char* argv[])
{
	int rank;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	printf("Power of 2^%d = %.2f\n", rank, pow(2,rank));

	MPI_Finalize();
}