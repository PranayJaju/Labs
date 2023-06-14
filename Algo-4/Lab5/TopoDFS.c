//Topological Sort using DFS

#include<stdio.h>
#include<stdlib.h>
#include"iStack.h"

//used for topological sorting of individual nodes
Stack* topo_sort_rec(int node, int vis[], int** adjMat, int n, Stack* s)
{
    //if node not visited only then apply topo sort
    if(!vis[node])
    {
        vis[node]=1;//node visited so make 1
        for(int i=0; i<n; i++)
            if(*(*(adjMat+node)+i))//if node points to another node then apply topo sort on it recursively
                topo_sort_rec(i, vis, adjMat, n, s);
        push(s, node);        
    }
    return s;
}

//uses topo_sort_rec to topological sort the entire graph 
void TopoSort(int** adjMat, int n)
{
    //initializing stack
    Stack* s=(Stack*)malloc(sizeof(Stack));
    (s->stack)=(int*)calloc(n+1, sizeof(int));
    s->size=n+1;
    s->top=-1;

    int vis[n];//node visited array
    for(int i=0; i<n; i++) vis[i]=0;//visted initially=0 for all nodes

    //topological sorting individual nodes usinf topo_sort_rec
    for(int i=0; i<n; i++)
        topo_sort_rec(i,vis,adjMat,n,s);

    //printing the stack contents top to bottom
    while(!isEmpty(s))
        printf("%d  ", pop(s));
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