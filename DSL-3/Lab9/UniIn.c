#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

Node* Union(Node* head1, Node* head2)
{
	Node* temp1=head1;
    Node* temp2=head2;
    Node* uni=copy(head1);
    int index=0;

    while(temp2)
    {
    	if(search(uni, temp2->data)==-1)
    		uni=insert(uni,temp2->data, -1);
    	temp2=temp2->link;
    }
    return uni;
}

Node* Intersection(Node* head1, Node* head2)
{
	Node* temp1=head1;
	Node* temp2=head2;
	Node* inter=NULL;

	while(temp1)
	{
		if(search(temp2, temp1->data)!=-1)
			inter=insert(inter, temp1->data, -1);
		temp1=temp1->link;
	}
	return inter;
}

int main()
{
	Node* head1=NULL;
    Node* head2=NULL;

    head1=insert(head1, 2, -1);
    head1=insert(head1, 5, -1);
    head1=insert(head1, 4, -1);
    head1=insert(head1, 7, -1);
    head1=insert(head1, 6, -1);

    head2=insert(head2, 3, -1);
    head2=insert(head2, 8, -1);
    head2=insert(head2, 6, -1);
    head2=insert(head2, 4, -1);

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    printf("Union: ");
    printList(Union(head1, head2));

    printf("Intersection: ");
    printList(Intersection(head1, head2));
}