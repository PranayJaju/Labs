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
    while(temp!=NULL)
    {
        printf("%d  ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void printListLast(Node* ll)
{
    Node* temp=last;
    while(temp!=NULL)
    {
        printf("%d  ", temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

int length(Node* ll)
{
    int length=0;
    Node* temp=ll;
    while(temp)
    {
        length++;
        temp=temp->next;
    }
    return length;
}

Node* insert(Node* ll, int data, int index)
{
    Node* temp=ll;
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=data;

    if(ll==NULL)
    {
        n->prev=NULL;
        n->next=NULL;
        ll=n;
        last=n;
    }
    else
    {
        if(index==0)
        {
            n->prev=NULL;
            n->next=ll;
            ll->prev=n;
            ll=n;
        }
        else if(index==-1)
        {
            while(temp->next)
            temp=temp->next;

            n->next=NULL;
            n->prev=temp;
            temp->next=n;
            last=n;
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

Node* deletePos(Node* ll, int index)
{
    Node* temp=ll;
    Node* previous=NULL;

    if(index==0)
    {
        ll=ll->next;
        ll->prev=NULL;
    }
    else if(index==-1)
    {
        last=last->prev;
        last->next=NULL;
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
    return ll;
}

Node* reverse(Node* ll)
{
    Node* temp=NULL;
    Node* current=ll;

    if(length(ll)==1)
    return ll;

    while(current)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    return temp->prev;
}