#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StudentLinkedList.h"

Student* sort(Student* head)
{
    Student* temp=(Student*)malloc(sizeof(Student));
    Student* current=head;
    Student* next=NULL;

    while(current)
    {
        next=current->link;
        while(next)
        {
            if(current->Data.marks < next->Data.marks)
                swap(current, next);
            next=next->link;
        }
        current=current->link;
    }
    return head;
}

int main()
{
    Student* head=NULL;
    head=insert(head, "Aman", 12, 45);
    head=insert(head, "Ram", 6, 89);
    head=insert(head, "Raju", 1, 60);
    printList(head);

    head=sort(head);
    printf("Sorted list based on marks:\n");
    printList(head);
    printf("Second highest:\n");
    Student* second=head->link;
    printf("%s,%d,%d\n", second->Data.name, second->Data.rollno, second->Data.marks);
}