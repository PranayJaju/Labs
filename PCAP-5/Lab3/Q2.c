#include<stdio.h>
#include<mpi.h>

double average(double a[], int n)
{
	double sum = 0.0;
	for(int i=0; i<n; i++)
		sum+=a[i];

	return sum/n;
}

int main(int argc, char* argv[])
{
	int rank, N, M;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &N);
	double arrIn[100], arrOut[N];
	
	if(rank==0)
	{
		printf("Enter a number: ");
		scanf("%d", &M);
		printf("Enter %d numbers: ", N*M);
		for(int i=0; i<N*M; i++)
			scanf("%lf", &arrIn[i]);
	}

	MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);
	double buffer[M];
	MPI_Scatter(arrIn, M, MPI_DOUBLE, buffer, M, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	double sub_avg = average(buffer, M);
	MPI_Gather(&sub_avg, 1, MPI_DOUBLE, arrOut, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	if(rank==0)
	{
		double avg = average(arrOut, N);
		printf("Average: %.3lf\n", avg);
	}

	MPI_Finalize();
}