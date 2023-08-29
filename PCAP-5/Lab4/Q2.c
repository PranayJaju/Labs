#include<stdio.h>
#include<mpi.h>

#define MCW MPI_COMM_WORLD

double f(double x)
{
	return 4.0/(1.0+x*x);
}

int main(int argc, char* argv[])
{
	int rank,size;
	int num_rect = 10000;
	double a = 0.0, b = 1.0;
	double width = (b-a)/num_rect;
	double local_sum = 0.0, global_sum = 0.0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	int local_num_rect = num_rect/size;
	int start = rank*local_num_rect;
	int end = start+local_num_rect;

	for(int i=start; i<end; i++)
	{
		double x = a + i*width;
		local_sum += f(x)+f(x+width);
	}
	local_sum = local_sum*width/2.0;

	MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MCW);
    if (rank == 0)
        printf("Approximation of π: %.10f\n", global_sum);

    MPI_Finalize();
}