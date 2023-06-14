#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* last=NULL;

void printList(Node* ll)
{
    Node* temp=ll;
    do
    {
        printf("%d  ", temp->data);
        temp=temp->next;
    }while(temp!=ll);
    printf("\n");
}

void printListLast(Node* ll)
{
    Node* temp=last;
    do
    {
        printf("%d  ", temp->data);
        temp=temp->prev;
    }while(temp!=last);
    printf("\n");
}

int length(Node* ll)
{
    int length=0;
    Node* temp=ll;
    if(!ll) return 0;
    do
    {
        length++;
        temp=temp->next;
    }while(temp!=ll);
    return length;
}

Node* insert(Node* ll, int data, int index)
{
    Node* temp=ll;
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=data;

    if(ll==NULL)
    {
        n->prev=n;
        n->next=n;
        ll=n;
        last=n;
    }
    else
    {
        if(index==0)
        {
            n->prev=last;
            n->next=ll;
            ll->prev=n;
            ll=n;
            last->next=n;
        }
        else if(index==-1)
        {
            while(temp->next!=ll)
            temp=temp->next;

            n->next=ll;
            n->prev=temp;
            temp->next=n;
            last=n;
            ll->prev=n;
        }
        else
        {
            for(int i=1; i<index; i++)
            temp=temp->next;

            n->prev=temp;
            n->next=temp->next;
            temp->next->prev=n;
            temp->next=n;
        }
    }
    return ll;
}

void deletePos(Node* ll, int index)
{
    Node* temp=ll;
    Node* previous=NULL;

    if(index==0)
    {
        ll=ll->next;
        ll->prev=last;
        last->next=ll;
    }
    else if(index==-1)
    {
        last=last->prev;
        last->next=ll;
        ll->prev=last;
    }
    else
    {
        for(int i=0; i<index; i++)
        {
            previous=temp;
            temp=temp->next;
        }
        previous->next=temp->next;
        temp->next->prev=previous;
    }
}