#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Count
{
    char* name;
    int occ;
    struct Count* link;
}Count;

void printListC(Count* list)
{
    Count* temp=list;
    while(temp)
    {
        printf("{%s,%d}  ", temp->name, temp->occ);
        temp=temp->link;
    }
    printf("\n");
}

Count* insertC(Count* head, char name[], int occ)
{
    Count* temp=(Count*)malloc(sizeof(Count));
    Count* n=(Count*)malloc(sizeof(Count));
    n->name=name;
    n->occ=occ;
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

        n->link=NULL;
        temp->link=n;
    }
    return head;
}

int searchC(Count* head, char* name)
{
    int flag=0;
    Count* temp=head;
    while(temp)
    {
        if(!strcmp(temp->name,name))
        {
            flag=1;
            break;
        }
        temp=temp->link;
    }
    return flag;
}