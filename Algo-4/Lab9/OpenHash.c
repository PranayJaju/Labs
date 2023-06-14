#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct hash_table
{
    int size;
    node **table;
} hash_table;

hash_table * create_hash_table(int size)
{
    hash_table *ht = (hash_table *)malloc(sizeof(hash_table));
    ht->size = size;
    ht->table = (node **)malloc(sizeof(node *) * size);
    for (int i = 0; i < size; i++) ht->table[i] = NULL;
    return ht;
}

int hash_function(int data, int size) { return data % size; }

void insert(hash_table *ht, int data)
{
    int index = hash_function(data, ht->size);
    node *new_node = (node *)malloc(sizeof(node));
    *new_node = (node){data, NULL};
    
    node *temp = ht->table[index];
    if (temp == NULL) ht->table[index] = new_node;
    else
    {
        while (temp->next != NULL) temp = temp->next;
        temp->next = new_node;
    }
}

int search(hash_table *ht, int data)
{
    int index = hash_function(data, ht->size);
    node *temp = ht->table[index];
    int data_comparisons = 0;
    while (temp != NULL)
    {
        data_comparisons++;
        if (temp->data == data) return data_comparisons;
        temp = temp->next;
    }
    return -1;
}

void print_hash_table(hash_table *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        printf("%d: ", i);
        node *temp = ht->table[i];
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int size, n;
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    printf("Enter the number of data: ");
    scanf("%d", &n);
    
    hash_table *ht = create_hash_table(size);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(ht, data);
    }
    
    print_hash_table(ht);
    
    int data;
    printf("Enter the data to search: ");
    scanf("%d", &data);
    int data_comparisons = search(ht, data);
    if (data_comparisons == -1) printf("Data not found\n");
    else printf("Data found in %d data comparisons\n", data_comparisons);
}