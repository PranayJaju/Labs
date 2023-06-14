#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
}Node;

void printList(Node* cll)
{
    Node* temp=cll;
    if(cll==NULL)
        printf("List is empty.\n");
    else
    {
        do
        {
            printf("%d -> ",temp->data);
            temp=temp->link;
        }while(temp->link!=cll);
        printf("%d", temp->data);
        printf("\n");
    }
}

Node* insert(Node* cll, int data, int index)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    Node* new=(Node*)malloc(sizeof(Node));
    
    new->data=data;

    if(cll==NULL)
    {
        cll=(Node*)malloc(sizeof(Node));
        new->link=new;
        cll=new;
    }
    else
    {
        if(index==0)
        {
            new->link=cll;

            temp=cll;
            while(temp->link!=cll)
                temp=temp->link;
            
            temp->link=new;
            cll=new;
        }
        else if(index==-1)
        {
            new->link=cll;
    
            temp=cll;
            while(temp->link!=cll)
                temp=temp->link;
    
            temp->link=new;    
        }
        else
        {
            temp=cll;
            
            for(int i=1; i<index; i++)
            temp=temp->link;

            new->link=temp->link;
            temp->link=new;
        }
    }
    return cll;
}

int length(Node* cll)
{
    int length=0;
    Node* temp=cll;
    do 
    {
        length++;
        temp=temp->link;
    }while(temp!=cll);

    return length;
}

int getElement(Node* cll, int index)
{
    Node* temp=cll;
    for(int i=0; i<index; i++)
    temp=temp->link;

    return temp->data;
}

Node* deletePos(Node* cll, int index)
{
    Node* temp=cll;
    Node* next=cll->link;
    Node* previous=NULL;
    
    if(index==0)//deleting the first node
    {
        while(temp->link!=cll)
        temp=temp->link;
        temp->link=cll->link;
        cll=cll->link;
    }
    else if(index==-1)//deleting the last node
    {
        while(next->link!=cll)
        {
            temp=temp->link;
            next=next->link;
        }
        temp->link=cll;
    }
    else//deleting any middle node
    {
        for(int i=0; i<index; i++)
        {
            previous=temp;
            temp=temp->link;
        }
        previous->link=temp->link;
    }
    
    return cll;
}