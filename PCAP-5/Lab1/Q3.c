#include<stdio.h>
#include"mpi.h"

int main(int argc, char* argv[])
{
	int rank;
	int a=26, b=8;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank==0) printf("%d+%d = %d\n", a, b, a+b);
	else if(rank==1) printf("%d-%d = %d\n", a, b, a-b);
	else if(rank==2) printf("%d*%d = %d\n", a, b, a*b);
	else printf("%d/%d = %d\n", a, b, a/b);

	MPI_Finalize();
}