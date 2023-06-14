#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Nodeptr
{
    char ch;
    struct Nodeptr* link;
}Nodeptr;

void printList(Nodeptr* head)
{
    Nodeptr* temp=head;
    while(temp)
    {
        printf("%c ", temp->ch);
        temp=temp->link;
    }
    printf("\n");
}

Nodeptr* insert(Nodeptr* head, char a)
{
    Nodeptr* temp=(Nodeptr*)malloc(sizeof(Nodeptr));
    Nodeptr* n=(Nodeptr*)malloc(sizeof(Nodeptr));
    n->ch=a;
    n->link=NULL;
    if(head==NULL)
    {
        head=n;
        head->link=NULL;
    }
    else
    {
        temp=head;
        while(temp->link)
        temp=temp->link;

        temp->link=n;
    }
    return head;
}

Nodeptr* deleteData(Nodeptr* head, char ch)
{
    Nodeptr* temp=head;
    Nodeptr* next=head->link;
    Nodeptr* previous=NULL;

    while(next)
    {
        if(temp->ch==ch)
        {
            previous->link=next;
        }
        previous=temp;
        temp=temp->link;
        next=next->link;
    }
    if(temp->ch==ch)//if the le==data
    previous->link=NULL;

    return head;
}