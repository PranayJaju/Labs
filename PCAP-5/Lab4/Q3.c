#include<stdio.h>
#include<mpi.h>

#define MCW MPI_COMM_WORLD

int main(int argc, char* argv[])
{
	int rank, size;
	int mat[3][3], ele, inter[3];
	int count = 0, res;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	if (rank==0) 
	{
        printf("Enter the 3x3 matrix:\n");
        for(int i=0; i<3; i++) 
            for(int j=0; j<3; j++) 
                scanf("%d", &mat[i][j]);

        printf("Enter the element to be searched: ");
        scanf("%d", &ele);
    }

    MPI_Bcast(&ele, 1, MPI_INT, 0, MCW);
    MPI_Scatter(mat, 3, MPI_INT, inter, 3, MPI_INT, 0, MCW);

    for(int i=0; i<3; i++)
    	if(inter[i]==ele)
    		count++;

	MPI_Reduce(&count, &res, 1, MPI_INT, MPI_SUM, 0, MCW);

	if(rank==0)
		printf("No.of occurences: %d\n", res);

	MPI_Finalize();
}