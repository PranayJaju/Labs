#include<stdio.h>
#include<stdlib.h>
#include"DoubleLL.h"

int main()
{
    Node* ll=NULL;

    ll=insert(ll,1,-1);
    ll=insert(ll,2,0);
    ll=insert(ll,3,-1);
    ll=insert(ll,4,0);
    ll=insert(ll,5,-1);
    ll=insert(ll,6,0);
    printList(ll);
    
    ll=deletePos(ll,0);
    ll=deletePos(ll,-1);
    printList(ll);
}