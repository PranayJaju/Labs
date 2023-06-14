#include<stdio.h>
#include<stdlib.h>

int opCount=0;

void Floyd(int** adjMat, int n)
{
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			opCount++;
			if(k==i || k==j) continue;
			else adjMat[i][j]=adjMat[i][k]+adjMat[k][j]>adjMat[i][j]?adjMat[i][j]:adjMat[i][k]+adjMat[k][j];
		}
	}
}

int main()
{
	int n;
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	int** adjMat=(int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++)
		adjMat[i]=(int*)malloc(sizeof(int)*n);
	printf("Enter adjacency matrix.\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &adjMat[i][j]);

	Floyd(adjMat, n);

	printf("After applying Floyd's algo.\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d  ", adjMat[i][j]);
		printf("\n");
	}
	printf("OpCount: %d\n", opCount);
}