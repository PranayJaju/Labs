#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 100
#define MAX_VERTICES 100

typedef struct Edge 
{
    int source, destination, weight;
} e;

typedef struct Graph 
{
    int num_vertices, num_edges;
    e edges[MAX_EDGES];
} graph;

typedef struct Subset 
{
    int parent, rank;
} s;

int find(s subsets[], int i) 
{
    if (subsets[i].parent != i) 
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void unionSet(s subsets[], int x, int y) {
    int x_root = find(subsets, x);
    int y_root = find(subsets, y);

    if (subsets[x_root].rank < subsets[y_root].rank) 
    {
        subsets[x_root].parent = y_root;
    } 
    else if (subsets[x_root].rank > subsets[y_root].rank) 
    {
        subsets[y_root].parent = x_root;
    } 
    else 
    {
        subsets[y_root].parent = x_root;
        subsets[x_root].rank++;
    }
}

void kruskal(graph graph) 
{
    s subsets[MAX_VERTICES];
    int num_edges_selected = 0;
    int i = 0, j = 0;
    int total_weight = 0;

    for (i = 0; i < graph.num_vertices; i++) 
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    for (i = 0; i < graph.num_edges; i++) 
    {
        for (j = i + 1; j < graph.num_edges; j++) 
        {
            if (graph.edges[i].weight > graph.edges[j].weight) 
            {
                e temp = graph.edges[i];
                graph.edges[i] = graph.edges[j];
                graph.edges[j] = temp;
            }
        }
    }

    i = 0;
    while (num_edges_selected < graph.num_vertices - 1) 
    {

        e next_edge = graph.edges[i++];
        int x = find(subsets, next_edge.source);
        int y = find(subsets, next_edge.destination);

        if (x != y) 
        {
            unionSet(subsets, x, y);
            printf("%d --- %d; Cost %d\n", next_edge.source, next_edge.destination, next_edge.weight);
            total_weight += next_edge.weight;
            num_edges_selected++;
        }
    }

    printf("Total weight of minimum cost spanning tree: %d\n", total_weight);
}

int main() 
{
    int num_vertices, num_edges;
    graph graph;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    printf("Enter the edges and their weights: \n");
    for (int i = 0; i < num_edges; i++) 
    {
        scanf("%d %d %d", &graph.edges[i].source, &graph.edges[i].destination, &graph.edges[i].weight);
    }

    graph.num_vertices = num_vertices;
    graph.num_edges = num_edges;

    kruskal(graph);

    return 0;
}