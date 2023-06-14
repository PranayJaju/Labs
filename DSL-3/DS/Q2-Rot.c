#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

int main()
{
    Node* head=NULL;
    
    head=insert(head, 3, 0);
    head=insert(head, 4, -1);
    head=insert(head, 5, -1);
    head=insert(head, 6, -1);
    head=insert(head, 7, -1);

    Node* copyList=copy(head);
    
    int k;
    printf("Enter value of k: ");
    scanf("%d", &k);

    for(int i=0; i<k; i++)
    {
        head=insert(head, getElement(head, 0), -1);
        head=deletePos(head, 0);
    }

    for(int i=0; i<length(copyList)-k; i++)
    {
        copyList=insert(copyList, getElement(copyList, 0), -1);
        copyList=deletePos(copyList, 0);
    }
 
    printf("Left Rotate: "); 
    printList(head);
    printf("Right Rotate: ");
    printList(copyList);
}