//This code only works for connected graphs.
#include<stdio.h>
#include<stdlib.h>

void DFS(int** adjMat, int* vis, int ver, int n)//DFS traversal
{
	*(vis+ver)=1;//making visited node 1
	printf("%d  ",ver);
	for(int i=0; i<n; i++)
		if(!*(vis+i) && *(*(adjMat+ver)+i))
			DFS(adjMat,vis,i,n);//if i_th node is not visited and is connected to current node, apply DFS on it
}

int** AdjMat(int n)//taking adjacency matrix as input
{
	int** AM=(int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++)
		*(AM+i)=(int*)calloc(n,sizeof(int));
	
	printf("Enter Adjacent Matrix.\n");
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", *(AM+i)+j);

	return AM;
}

int main()
{
	int n, ver;
	printf("Enter no.of vertices.\n");
	scanf("%d", &n);
	int** AM=AdjMat(n);
	int* vis=(int*)calloc(n,sizeof(int));
	printf("Enter vertex to start from.\n");
	scanf("%d", &ver);
	printf("DFS: ");
	DFS(AM,vis,ver,n);
	printf("\n");
}

//Take this as input for AM.(Can hardcode to make it easy)
/*{{0, 1, 1, 0, 0, 0},
  {1, 0, 0, 0, 1, 0},
  {1, 0, 0, 1, 1, 1},
  {0, 0, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1},
  {0, 0, 1, 1, 1, 0}};*/
//Output for vertex 0: 0 1 4 2 3 5
//Output for Vertex 1: 2 0 1 4 5 3