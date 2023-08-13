#include<stdio.h>
#include<string.h>
#include<mpi.h>

int main(int argc, char* argv[])
{
    int rank;
    char word[20];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    if(rank==0)
    {
        printf("Enter a word: ");
        fflush(stdout);
        scanf("%s", word);
        MPI_Ssend(word, sizeof(word), MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(word, sizeof(word), MPI_CHAR, 1, 0, MPI_COMM_WORLD, &status);
        printf("Toggled word: %s", word);
    }
    else
    {
        MPI_Recv(word, sizeof(word), MPI_CHAR, 0, 0, MPI_COMM_WORLD, &status);
        for(int i=0; i<strlen(word); i++)
            word[i] ^= 32;
        MPI_Ssend(word, sizeof(word), MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}