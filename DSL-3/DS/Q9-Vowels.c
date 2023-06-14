#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CharLinkedList.h"

char vowels[]={'A','E','I','O','U','a','e','i','o','u'};

Nodeptr* create(Nodeptr* head, char name[])
{
    for(int i=0; i<strlen(name); i++)
        head=insert(head, name[i]);

    return head;
}

void allVowels(Nodeptr* head)
{
    for(int i=0; i<10; i++)
        head=deleteData(head, vowels[i]);
}

int main()
{
    char name[]="Pranay";
    Nodeptr* head=NULL;
    head=create(head, name);
    printList(head);
    allVowels(head);
    printList(head);
}