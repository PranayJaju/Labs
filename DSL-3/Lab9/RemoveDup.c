#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

Node* removeDup(Node* head)
{
	Node* temp=head;
	for(int i=1; i<length(temp); i++)
	{
		if(getElement(temp, i)==getElement(temp, i-1))
		{
			temp=deletePos(temp, i);
			i--;
		}
	}
	return temp;
}

int main()
{
	Node* head=NULL;

	head=insert(head,1,-1);
	head=insert(head,1,-1);
	head=insert(head,2,-1);
	head=insert(head,2,-1);
	head=insert(head,2,-1);
	head=insert(head,3,-1);
	head=insert(head,3,-1);
	head=insert(head,3,-1);
	head=insert(head,3,-1);
	head=insert(head,4,-1);
	head=insert(head,4,-1);
	head=insert(head,5,-1);
	
	printf("Original List:\n");
	printList(head);

	printf("List after removing duplicates:\n");
	head=removeDup(head);
	printList(head);
}