#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int main()
{
	int vertices, edges;
	printf("Enter number of vertices and edges.\n");
	scanf("%d %d", &vertices, &edges);
	int adjMat[vertices][vertices];

	for(int i=0; i<vertices; i++)
		for(int j=0; j<vertices; j++)
			adjMat[i][j]=0;

	for(int i=0; i<edges; i++)
	{
		int e1, e2;
		printf("Enter edge %d connections.\n", i+1);
		scanf("%d %d", &e1, &e2);
		adjMat[e1][e2]=1;
		adjMat[e2][e1]=1;
	}

	printf("Adjacency Matrix:\n");
	for(int i=0; i<vertices; i++)
	{
		for(int j=0; j<vertices; j++)
			printf("%d ", adjMat[i][j]);
		printf("\n");
	}

	Node* heads[vertices];

	for(int i=0; i<vertices; i++)
		heads[i]=NULL;

	for(int i=0; i<vertices; i++)
		for(int j=0; j<vertices; j++)
			if(adjMat[i][j]==1)
				heads[i]=insert(heads[i], j, -1);

	printf("Adjacency List:\n");
	for(int i=0; i<vertices; i++)
	{
		printf("%d -> ",i);
		printList(heads[i]);
	}
}