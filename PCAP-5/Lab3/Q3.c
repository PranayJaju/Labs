#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<mpi.h>

int noVowel(char word[], int len)
{
	int no_vowel = 0;
	for(int i=0; i<len; i++)
	{
		char ch = tolower(word[i]);
		if(ch!='a'&&ch!='e'&&ch!='i'&&ch!='o'&&ch!='u')
			no_vowel++;
	}
	return no_vowel;
}

int main(int argc, char* argv[])
{
	int rank, N;
	char word[50];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &N);
	int arrOut[N];

	if(rank==0)
	{
		printf("Enter a word: ");
		scanf("%s", word);
	}

	int len = strlen(word)/N;
	MPI_Bcast(&len, 1, MPI_INT, 0, MPI_COMM_WORLD);
	char buffer[len];
	MPI_Scatter(word, len, MPI_CHAR, buffer, len, MPI_CHAR, 0, MPI_COMM_WORLD);
	int nv = noVowel(buffer, len);
	MPI_Gather(&nv, 1, MPI_INT, arrOut, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank==0)
	{
		int total_no_vowel = 0;
		for(int i=0; i<N; i++)
		{
			printf("No.of no vowels from process %d: %d\n", i, arrOut[i]);
			total_no_vowel+=arrOut[i];
		}
		printf("Total no.of of no vowels: %d\n", total_no_vowel);
	}

	MPI_Finalize();
}