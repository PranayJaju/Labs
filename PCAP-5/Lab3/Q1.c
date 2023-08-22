#include<stdio.h>
#include<mpi.h>

int fact(int n)
{
	if(n==0) return 1;
	return n*fact(n-1);
}

int main(int argc, char* argv[])
{
	int rank, N, c;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &N);
	int arrIn[N], arrOut[N];

	if(rank==0)
	{
		printf("Enter %d nos: ", N);
		for(int i=0; i<N; i++)
			scanf("%d", &arrIn[i]);	
	}

	MPI_Scatter(arrIn, 1, MPI_INT, &c, 1, MPI_INT, 0, MPI_COMM_WORLD);
	int f = fact(c);
	MPI_Gather(&f, 1, MPI_INT, arrOut, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank==0)
	{
		int fact_sum=0;
		for(int i=0; i<N; i++)
			fact_sum+=arrOut[i];
		printf("Factorial Sum: %d\n",fact_sum);
	}

	MPI_Finalize();
}