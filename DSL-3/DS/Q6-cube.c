#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"LinkedList.h"

int main()
{
    Node* head=NULL;
    Node* Even=NULL;
    Node* Odd=NULL;

    head=insert(head, 1, 0);
    head=insert(head, 2, -1);
    head=insert(head, 3, -1);
    head=insert(head, 4, -1);
    head=insert(head, 5, -1);
    head=insert(head, 6, -1);
    head=insert(head, 7, -1);
    printf("Sample nodes of the original list:\n");
    printList(head);

    Node* temp=head;
    while(temp)
    {
        if((temp->data)%2==0)
            Even=insert(Even, pow(temp->data,3), -1);
        else
            Odd=insert(Odd, pow(temp->data, 3), -1);
        temp=temp->link; 
    }

    printf("Displaying the elements of LIST-1 followed by LIST-2:\n");
    printf("LIST1: ");
    printList(Even);
    printf("LIST2: ");
    printList(Odd);
}