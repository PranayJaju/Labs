#include<stdio.h>
#include"mpi.h"

int main(int argc, char* argv[])
{
	int rank;
	char str[]="HeLlOwoRLd";

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	str[rank] ^= 32;
	printf("%s\n", str);

	MPI_Finalize();
}