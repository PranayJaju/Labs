#include<stdio.h>
#include<mpi.h>

int main(int argc, char* argv[])
{
    int rank, N;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &N);
    MPI_Status status;

    int buff_size = BUFSIZ;
    int buffer[buff_size];
    MPI_Buffer_attach(buffer, buff_size);

    if(rank==0)
    {
        int arr[N];
        printf("Enter %d numbers: ", N);
        fflush(stdout);
        for(int i=0; i<N; i++)
            scanf("%d", &arr[i]);
        for(int i=1; i<N; i++)
            MPI_Bsend(&arr[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD); 
    }
    else 
    {
        int og, x;
        MPI_Recv(&og, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        if(rank%2==0) x = og*og;
        else x = og*og*og;
        printf("Rank: %d | OG: %d | New: %d\n", rank, og, x);
    }
    MPI_Buffer_detach(&buffer, &buff_size);
    MPI_Finalize();
}