#include<stdio.h>
#include<mpi.h>

#define MCW MPI_COMM_WORLD

void ErrorHandler(int err_code){
    if(err_code != MPI_SUCCESS){
        char error_string[BUFSIZ];
        int length_err_string, err_class;
        MPI_Error_class(err_code, &err_class);
        MPI_Error_string(err_code, error_string, &length_err_string);
        fprintf(stderr, "Error: %d %s\n", err_class, error_string);
    }
}

int main(int argc, char* argv[])
{
	int rank,size, err_code;
	int fact=1, factsum;

	MPI_Init(&argc, &argv);
	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
	MPI_Comm_rank(MCW, &rank);
	MPI_Comm_size(MCW, &size);

	for(int i=1; i<=rank+1; i++)
		fact*=i;

	err_code = MPI_Scan(&fact, &factsum, 1, MPI_INT, MPI_SUM, MCW);
	ErrorHandler(err_code);
	if(rank==size-1) printf("Total Factorial Sum: %d\n", factsum);
	MPI_Finalize();
}