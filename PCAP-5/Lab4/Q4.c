#include<stdio.h>
#include<mpi.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char* argv[])
{
	int rank, size;
	int mat[4][4], inter[4], matS[4], out[4][4];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	if(rank==0)
	{
		printf("Enter the 4x4 matrix:\n");
        for(int i=0; i<4; i++) 
            for(int j=0; j<4; j++) 
                scanf("%d", &mat[i][j]);
	}

	MPI_Scatter(mat, 4, MPI_INT, inter, 4, MPI_INT, 0, MCW);
	MPI_Scan(inter, matS, 4, MPI_INT, MPI_SUM, MCW);
	MPI_Gather(matS, 4, MPI_INT, out, 4, MPI_INT, 0, MCW);

	if(rank==0)
	{
		printf("Output Matrix: \n");
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
				printf("%d  ", out[i][j]);
			printf("\n");
		}
	}

	MPI_Finalize();
}