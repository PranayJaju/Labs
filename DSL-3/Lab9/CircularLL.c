#include<stdio.h>
#include<stdlib.h>
#include"CircularLinkedList.h"

Node* Merge(Node* head1, Node* head2)
{
    Node* temp1=head1;
    Node* temp2=head2;
    Node* merge=head1;
    int index=0;

    while(temp2->link!=head2)
    {
        if(temp1->link==head1) break;
        while(temp2->data > temp1->data)
        {
            temp1=temp1->link;
            index++;
        }
        merge=insert(merge, temp2->data, index);
        index++;
        temp2=temp2->link;
    }

    while(temp2->link!=head2->link)
    {
        merge=insert(merge, temp2->data, -1);
        temp2=temp2->link;
    }

    return merge;
}

int main()
{
    Node* head1=NULL;
    Node* head2=NULL;

    head1=insert(head1, 2, 0);
    head1=insert(head1, 4, -1);
    head1=insert(head1, 6, -1);
    head1=insert(head1, 8, -1);

    head2=insert(head2, 3, 0);
    head2=insert(head2, 5, -1);
    head2=insert(head2, 7, -1);
    head2=insert(head2, 9, -1);

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    head1=Merge(head1, head2);
    printf("Merged list: ");
    printList(head1);
}