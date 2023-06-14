//Topological Sorting using Source Removal Method

#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

//to get the indegree of a node
int indegree(int node, int** adjMat, int n)
{
    int indeg=0;
    for(int i=0; i<n; i++)
        if(*(*(adjMat+i)+node)==1)
            indeg++;
    return indeg;
}

void TopoSort(int** adjMat, int n)
{
    //initializing queue
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->queue=(int*)calloc(2*n, sizeof(int));
    q->front=-1;
    q->rear=-1;
    q->size=2*n;

    int indeg[n]; int toposorted[n];
    int count=0;//count of visited vertices

    for(int i=0; i<n; i++)//getting indegree of every node
    {   
        indeg[i]=0; toposorted[i]=0; 
        indeg[i]=indegree(i,adjMat, n);
        if(indeg[i]==0)//if indegree is 0, add to queue
        enqueue(q,i);
    }

    while(!isEmpty(q))
    {
        int v=dequeue(q);
        toposorted[count++]=v;//adding v to topological sorted array
        for(int i=0; i<n; i++)
        {
            if(*(*(adjMat+v)+i))
            {
                *(*(adjMat+v)+i)=0;//for node v, removing edges to neighbour
                indeg[i]--;//decreasing neighbour's indegree
                if(indeg[i]==0) enqueue(q,i);
            }
        }
    }

    for(int i=0; i<n; i++)
        printf("%d  ", toposorted[i]);
}

int** AdjMat(int n)//taking adjacency matrix as input
{
	int** AM=(int**)malloc(sizeof(int*)*n);//array of pointers for adj matrix
	for(int i=0; i<n; i++)
		*(AM+i)=(int*)calloc(n,sizeof(int));//initializing individual pointers of adj matrix
	
	printf("Enter Adjacent Matrix.\n");//taking input of adj matrix
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", *(AM+i)+j);

	return AM;
}

int main()
{
    int n;
	printf("Enter no.of vertices.\n");
	scanf("%d", &n);
	int** AM=AdjMat(n);

    printf("Topological sort of given graph: ");
    TopoSort(AM, n);
}