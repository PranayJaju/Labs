#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[])
{
    int rank, x=1;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    if(rank==0)
    {
        MPI_Ssend(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        // printf("Deadlock0\n");
        // fflush(stdout);
        MPI_Recv(&x, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        printf("No recv: %d", x);
    }
    else
    {
        MPI_Ssend(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        // printf("Deadlock1\n");
        // fflush(stdout);
        MPI_Recv(&x, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("No recv: %d", x);
    }
    MPI_Finalize();
}