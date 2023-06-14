#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    char* word;
    struct Node* prev;
    struct Node* next;
}Node;

Node* last=NULL;

void printList(Node* ll)
{
    Node* temp=ll;
    while(temp!=NULL)
    {
        printf("%s  ", temp->word);
        temp=temp->next;
    }
    printf("\n");
}

void printListLast(Node* ll)
{
    Node* temp=last;
    while(temp!=NULL)
    {
        printf("%s  ", temp->word);
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

Node* insert(Node* ll, char word[], int index)
{
    Node* temp=ll;
    Node* new=(Node*)malloc(sizeof(Node));
    new->word=word;

    if(ll==NULL)
    {
        new->prev=NULL;
        new->next=NULL;
        ll=new;
        last=new;
    }
    else
    {
        if(index==0)
        {
            new->prev=NULL;
            new->next=ll;
            ll->prev=new;
            ll=new;
        }
        else if(index==-1)
        {
            while(temp->next)
            temp=temp->next;

            new->next=NULL;
            new->prev=temp;
            temp->next=new;
            last=new;
        }
        else
        {
            for(int i=1; i<index; i++)
            temp=temp->next;

            new->prev=temp;
            new->next=temp->next;
            temp->next->prev=new;
            temp->next=new;
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
    //return ll;
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

int main()
{
    Node* ll=NULL;

    ll=insert(ll,"hello",-1);
    ll=insert(ll,"bonjour",-1);
    ll=insert(ll,"hola",-1);
    ll=insert(ll,"hallo",-1);
    ll=insert(ll,"hej",-1);
    ll=insert(ll,"aloha",-1);
    printf("Original list: ");
    printList(ll);

    ll=reverse(ll);
    printf("Reversed list: ");
    printList(ll);
}