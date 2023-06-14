#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int main()
{
    Node* head=NULL;
    int n, data;
    printf("Enter number of nodes to be created: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        printf("Enter data of node %d: ", i);
        scanf("%d", &data);
        head=insert(head, data, -1);
    }
    printf("\nData in list before deletion\n");
    printList(head);

    int key;
    printf("Enter element value of key to be considered for deletion: ");
    scanf("%d", &key);

    printf("Data in the final list after deletion\n");
    head=deleteData(head, key*key);
    printList(head);
}