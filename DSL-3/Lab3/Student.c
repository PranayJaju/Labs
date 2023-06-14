#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int I;
typedef struct
{
	char name[50];
	int rollNo;
	double CGPA;
}Student;

void display(Student* s)
{
    printf("Name: %s", s->name);
    printf("Roll No: %d\n", s->rollNo);
    printf("CGPA: %.2lf\n", s->CGPA);
}

void main()
{
	Student* i, *j; Student temp;
	int n; char x;
	printf("Enter no.of students.\n");
	scanf("%d", &n);
	Student* s=(Student*)calloc(n, sizeof(Student));
    for(i=s; i<s+n; i++)
    {
    	printf("Name: ");
    	scanf("%c", &x);
    	fgets(i->name, 50, stdin);
    	printf("Roll No and CGPA: ");
        scanf("%d %lf", &i->rollNo, &i->CGPA);
    }

    for(I=0; I<n-1; I++)
    {
    	for(j=s; j<s+(n-1-I); j++)
    	{
    		if(j->rollNo>(j+1)->rollNo)
    		{
                temp=*j;
                *j=*(j+1);
                *(j+1)=temp;
    		}
    	}
    }

    printf("\n");

    for(i=s; i<s+n; i++)
    {
    	display(i);
    	printf("\n");
    }
    
    free(s);
}
