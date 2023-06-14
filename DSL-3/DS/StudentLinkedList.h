#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
    struct data
    {
        char name[50];
        int rollno;
        int marks;
    }Data;
    struct Student* link;
}Student;

void printList(Student* head)
{
    Student* temp=head;
    while(temp)
    {
        printf("{%s, %d, %d}  ", temp->Data.name, temp->Data.rollno, temp->Data.marks);
        temp=temp->link;
    }
    printf("\n");
}

Student* insert(Student* head, char name[], int rollno, int marks)
{
    Student* temp=(Student*)malloc(sizeof(Student));
    Student* n=(Student*)malloc(sizeof(Student));
    strcpy(n->Data.name, name);
    n->Data.rollno=rollno;
    n->Data.marks=marks;

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

void swap(Student* a, Student* b)
{
    Student* temp=(Student*)malloc(sizeof(Student));
    temp->Data=a->Data;
    a->Data=b->Data;
    b->Data=temp->Data;
}
