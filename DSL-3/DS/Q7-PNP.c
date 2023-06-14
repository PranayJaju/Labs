#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StringLinkedList.h"

int Palin(char word[50])
{
    int length=strlen(word), flag=0;
    for(int i=0; i<length/2; i++)
    {
        if(word[i]!=word[length-i-1])
        {
            flag=1;
            break;
        }
    }
    return !flag;
}

int main()
{
    Nodeptr* head=NULL;
    Nodeptr* PSLIST=NULL;
    Nodeptr* NPSLIST=NULL;

    head=insert(head, "SIRI");
    head=insert(head, "MAM");
    head=insert(head, "lila");
    head=insert(head, "CAC");
    printList(head);

    Nodeptr* temp=head;
    while(temp)
    {
        if(Palin(temp->word))
            PSLIST=insert(PSLIST, temp->word);
        else
            NPSLIST=insert(NPSLIST, temp->word);

        temp=temp->link;    
    }

    printf("1. ");
    printList(PSLIST);
    printf("2. ");
    printList(NPSLIST);
}