#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"

int main()
{
    Node* Fib=NULL;
    Fib=insert(Fib, 0, 0);
    Fib=insert(Fib, 1, -1);

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    Node* F1=Fib;
    Node* F2=Fib->link;

    for(int i=2; i<n; i++)
    {
        int fibbonext=F1->data+F2->data;
        Fib=insert(Fib, fibbonext, -1);
        F1=F1->link;
        F2=F2->link;
    }
    printList(Fib);
}