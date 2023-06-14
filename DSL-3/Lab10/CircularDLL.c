#include<stdio.h>
#include<stdlib.h>
#include"CircularDLL.h"

int main()
{
    Node* ll=NULL;

    ll=insert(ll,3,-1);
    ll=insert(ll,4,-1);
    ll=insert(ll,5,-1);
    ll=insert(ll,6,-1);
    ll=insert(ll,7,-1);
    printList(ll);
    printf("length: %d\n", length(ll));
    printListLast(ll);
    deletePos(ll,-1);
    printList(ll);
}