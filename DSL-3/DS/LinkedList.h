#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* link;
}Node;

//function to print the given Linked List
void printList(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d  ", temp->data);
        temp=temp->link;
    }
    printf("\n");
}

//function to insert a new node at given index
Node* insert(Node* head, int data, int index)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    Node* new=(Node*)malloc(sizeof(Node));
    
    if(head==NULL)//to create a linked list
    {
        new->data=data;
        new->link=head;
        head=new;
    }
    else
    {
        if(index==0)//to append at first element
        {
            new->data=data;
            new->link=head;
            head=new;
        }
        else if(index==-1)//to append at the last element
        {
            temp=head;
            while(temp->link)
            temp=temp->link;

            new->data=data;
            new->link=NULL;
            temp->link=new;
        }
        else//to append in between
        {
            temp=head;
            for(int i=1; i<index; i++)
            temp=temp->link;

            new->data=data;
            new->link=temp->link;
            temp->link=new;
        }
    }
    
    return head;
}

//function to delete node at particular index
Node* deletePos(Node* head, int index)
{
    Node* temp=head;
    Node* next=head->link;
    Node* previous=NULL;
    
    if(index==0)//deleting the first node
    head=head->link;
    else if(index==-1)//deleting the last node
    {
        while(next->link)
        {
            temp=temp->link;
            next=next->link;
        }
        temp->link=NULL;
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
    
    return head;
}

//function to delete a node with a particular data
Node* deleteData(Node* head, int data)
{
    Node* temp=head;
    Node* next=head->link;
    Node* previous=NULL;

    while(next)
    {
        if(temp->data==data)
        {
            previous->link=next;
        }
        previous=temp;
        temp=temp->link;
        next=next->link;
    }
    if(temp->data==data)//if the le==data
    previous->link=NULL;

    return head;
}

//get element at the specified index
int getElement(Node* head, int index)
{
    Node* temp=head;
    for(int i=0; i<index; i++)
    temp=temp->link;

    return temp->data;
}

//function to calculate length of linked list, ie, no.of nodes
int length(Node* head)
{
    Node* temp=head;
    int count=0;
    while(temp)
    {
        temp=temp->link;
        count++;
    }
    return count;
}

//function to reverse the linked list
Node* reverse(Node* head)
{
    Node* previous=NULL;
    Node* current=head;
    Node* next;
    while(current)
    {
        next=current->link;
        current->link=previous;
        previous=current;
        current=next;
    }
    return previous;
}

//funciton to sort the linked list
//reversed = 0 for ascending, 1 for descending
Node* sort(Node* head, int reversed)
{
    int temp;
    Node* current=head;
    Node* next=NULL;

    while(current)
    {
        next=current->link;
        while(next)
        {
            if(current->data > next->data)
            {
                temp=current->data;
                current->data=next->data;
                next->data=temp;
            }
            next=next->link;
        }
        current=current->link;
    }
    
    if(!reversed)
        return head;
    else//if descending order is required
        return reverse(head);
}

//function to search for a given element in the list and return 
//its index, if found or else -1
int search(Node* head, int data)
{
    int flag=0, index=0;
    Node* temp=head;
    while(temp)
    {
        if(temp->data==data)
        {
            flag=1;
            break;
        }
        temp=temp->link;
        index++;
    }

    if(flag)//checking if the element was found or not 
        return index;
    else
        return -1;
}

//to copy on linked list into another
Node* copy(Node* head)
{
    Node* copied=NULL;
    Node* temp=head;
    while(temp)
    {
        copied=insert(copied, temp->data, -1);
        temp=temp->link;
    }
    return copied;
}