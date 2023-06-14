#include <stdio.h>
#include <stdlib.h>

typedef struct items
{
    int weight;
    int val;
} item;

void backtrace(item items[], int ** a, int num, int cap)
{   
    int i = num, j = cap;

    int res[num];
    for(int k = 0; k < num; k++) res[k] = 0;
    
    while(i > 0 && j > 0)
    {
        if(a[i][j] > a[i-1][j])
        {
            j -= items[i-1].weight;
            res[i-1] = 1;
        }
        i--;
    }
    
    printf("Total value is %d\n", a[num][cap]);
    printf("1/0 Vector is: ");
    for(int k = 0; k < num; k++) printf("%d ", res[k]);
    printf("\n");
}

int * knapsack(item items[], int num, int capacity)
{

    int res[num];
    for(int i = 0; i < num; i++) res[i] = 0;

    int m = num + 1, n = capacity + 1;

    int ** a = (int **) malloc(sizeof(int *) * m);
    for(int i = 0; i < m; i++)
    {
        a[i] = (int *) malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++) a[i][j] = 0;
    }

    for(int i = 1; i < m; i++)
    for(int j = 1; j < n; j++)
    {
        if(items[i-1].weight > j) a[i][j] = a[i-1][j];
        else
        {
            int prev = a[i-1][j];
            int added = a[i-1][j-items[i-1].weight] + items[i-1].val;

            a[i][j] = (prev > added) ? prev : added;
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }

    backtrace(items, a, num, capacity);
}

int main()
{

    int cap;
    printf("Enter capacity of knapsack: ");
    scanf("%d", &cap);

    int len;
    printf("Enter number of items: ");
    scanf("%d", &len);

    item items[len];
    printf("Enter weights and vals: \n");
    for(int i = 0; i < len; i++)
    {
        int w, v;
        printf("%d: ", i+1);
        scanf("%d %d", &w, &v);
        items[i] = (item) {w, v};
    }

    knapsack(items, len, cap);
}