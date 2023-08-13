#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[])
{
    int rank, size, x=10;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;

    if(rank==0)
        for(int i=1; i<size; i++)
        {
            x = x*i + i;
            MPI_Send(&x, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    else 
    {
        MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("Rank %d|No recv %d\n", rank, x);
    }    
    MPI_Finalize();
}