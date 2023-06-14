#include<stdio.h>
#include<stdlib.h>

typedef struct Nodeptr
{
    char* word;
    struct Nodeptr* link;
}Nodeptr;

void printList(Nodeptr* head)
{
    Nodeptr* temp=head;
    while(temp)
    {
        printf("%s  ", temp->word);
        temp=temp->link;
    }
    printf("\n");
}

Nodeptr* insert(Nodeptr* head, char word[])
{
    Nodeptr* temp=(Nodeptr*)malloc(sizeof(Nodeptr));
    Nodeptr* new=(Nodeptr*)malloc(sizeof(Nodeptr));
    new->word=word;
    if(head==NULL)
    {
        head=new;
        head->link=NULL;
    }
    else
    {
        temp=head;
        while(temp->link)
        temp=temp->link;

        new->link=NULL;
        temp->link=new;
    }
    return head;
}
