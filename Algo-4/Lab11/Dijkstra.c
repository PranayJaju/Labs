#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 999

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

void path(int parent[], int node)
{
	if(parent[node]==-1) 
	{
		printf("%d ", node);
		return;
	}
	path(parent, parent[node]);
	printf("%d ", node);
}

void Dijkstra(int** AdjMat, int start, int  n)
{
	int visited[n]; int distance[n]; int parent[n];
	int edgeNum=0; int nextNode;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(AdjMat[i][j]==0)
				AdjMat[i][j]=INT_MAX;

	for(int i=0; i<n; i++)
	{
	    distance[i]=AdjMat[start][i];
		visited[i]=0;
		parent[i]=-1;
	}

	distance[start]=0; visited[start]=1;edgeNum++;

	while(edgeNum<n-1)
	{
		int min_dist=INT_MAX;
		for(int i=0; i<n; i++)
			if(distance[i]<min_dist && !visited[i])
			{
				min_dist=distance[i];
				nextNode=i;
			}
		visited[nextNode]=1;

		for(int i=0; i<n ;i++)
			if(!visited[i])
				if(min_dist+AdjMat[nextNode][i]<distance[i])
				{
					distance[i]=min_dist+AdjMat[nextNode][i];
					parent[i]=nextNode;
				}

		edgeNum++;
	}

	printf("Shortest distance from vertex %d to other vertices:\n", start);
	for(int i=0; i<n; i++)
		if(i!=start)
		{
			printf("Vertex %d-> Distance: %d, Path: %d ", i, distance[i], start);
			path(parent,i);
			printf("\n");
		}
}

int main()
{
	int n, ver;
	printf("Enter no.of vertices.\n");
	scanf("%d", &n);
	int** AM=AdjMat(n);
	printf("Enter vertex to start from.\n");
	scanf("%d", &ver);
	Dijkstra(AM,ver,n);
}