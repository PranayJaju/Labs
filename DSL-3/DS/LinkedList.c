#include<stdio.h>
#include<stdlib.h>

typedef struct 
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
    else
        return head=reverse(head);
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

    if(flag)
        return index;
    else
        return -1;
}

int main()
{
    Node* head=NULL;

    head=insert(head, 3, 0);
    head=insert(head, 4, -1);
    head=insert(head, 5, -1);
    head=insert(head, 6, 1);
    head=insert(head, 7, 0);
    head=insert(head, 8, 3);
    head=insert(head, 9, 2);
    //List=[7,3,9,6,8,4,5]
    head=insert(head, 1, 0);
    head=insert(head, 2, 5);
    head=insert(head, 10, -1);
    //List=[1,7,3,9,6,2,8,4,5,10]

    printList(head);
    printf("Length of linked list is: %d\n", length(head));//10

    printf("Looking for 4 in list.\n");
    int search_result=search(head, 4);
    if(search_result!=-1)
        printf("4 found at index: %d\n", search_result);
    else
        printf("4 not found.\n");

    printf("Reversed Linked List:\n");
    head=reverse(head);
    printList(head);

    head=sort(head, 0);
    printf("Ascending sorted list:\n");
    printList(head);

    head=deletePos(head, 0);//deletes 1
    head=deletePos(head, -1);//deletes 10
    printf("Length of linked list is: %d\n", length(head));//8
    head=deletePos(head, 2);//deletes 9
    head=deletePos(head, 2);//deletes 6

    printList(head);

    head=insert(head, 6, -1);
    printList(head);
    head=insert(head, 6, 4);
    printList(head);
    head=deleteData(head, 6);
    printList(head);
}