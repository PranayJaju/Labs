#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int main()
{
    Node* head=NULL;
    Node* L1=NULL;
    Node* L2=NULL;

    head=insert(head, 1, 0);
    head=insert(head, 6, -1);
    head=insert(head, 5, -1);
    head=insert(head, 9, -1);
    head=insert(head, 4, -1);
    head=insert(head, 3, -1);
    head=insert(head, 7, -1);
    head=insert(head, 2, -1);
    head=insert(head, 8, -1);

    printf("Input List:\n");
    printList(head);

    Node* temp=head;int i=0;
    while(temp)
    {
        if(i%2==0)
            L1=insert(L1, temp->data, -1);
        else
            L2=insert(L2, temp->data, -1);

        i++;
        temp=temp->link;    
    }

    printf("L1: ");
    printList(L1);
    printf("L2: ");
    printList(L2);
}