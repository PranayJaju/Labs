#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StringLinkedList.h"
#include"CountLinkedList.h"

Nodeptr* Create(Nodeptr* head, char name[][10], int n)
{
    for(int i=0; i<n; i++)
        head=insert(head, name[i]);
    return head;    
}

void Search(Nodeptr* head)
{
    Count* list=NULL;
    Nodeptr* i=head;
    while(i)
    {
        if(searchC(list, i->word))
        {
            i=i->link;
            continue;
        }
        int c=1;
        Nodeptr* j=i->link;
        while(j->link)
        {
            if(!strcmp(i->word,j->word))
            c++;
            j=j->link;
        }
        if(!strcmp(i->word, j->word))
        c++;
        list=insertC(list, i->word, c);
        i=i->link;
    }
    printListC(list);
}

int main()
{
    Nodeptr* head=NULL;
    char names[10][10]={"pranay", "eshaan", "arnav", "pranay", "eshaan", "pranay", "harsh", "harsh"};
    head=Create(head, names, 8);
    printList(head);
    Search(head);
}