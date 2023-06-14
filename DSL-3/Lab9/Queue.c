#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int main()
{
	Node* queue=NULL;

	queue=insert(queue,1,-1);
	queue=insert(queue,2,-1);
	queue=insert(queue,3,-1);
	queue=insert(queue,4,-1);
	queue=insert(queue,5,-1);
	queue=insert(queue,6,-1);
	queue=insert(queue,7,-1);

	printf("Queue is: ");
	printList(queue);

	queue=deletePos(queue,0);
	queue=deletePos(queue,0);
	queue=deletePos(queue,0);

	printf("After deleting first 3 elements: ");
	printList(queue);
}