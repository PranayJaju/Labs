#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char name[50];
	int dob[3];
	struct{
	int houseNo;
	int zipcode;
	char state[20];
	}address;
}Employee;

void display(Employee* e)
{
	printf("Name: %s", e->name);
	printf("Date of Birth: %d/%d/%d\n",e->dob[0], e->dob[1], e->dob[2]);
	printf("Address: %d, %d, %s\n", e->address.houseNo, e->address.zipcode, e->address.state);
}

void main()
{
    int n; char x;
    printf("Enter no.of emplyee.\n");
    scanf("%d", &n);
    Employee* i;
	Employee* e=(Employee*)calloc(n, sizeof(Employee));
	for(i=e; i<e+n; i++)
	{
	    printf("Enter employee details.\n");
	    printf("Name: ");
		if(i==e)
	    scanf("%c", &x);
	    fgets(i->name, 50, stdin);
	    printf("Date of Birth: ");
	    scanf("%d %d %d", &i->dob[0], &i->dob[1], &i->dob[2]);\
	    printf("Address: ");
	    scanf("%d %d", &i->address.houseNo, &i->address.zipcode);
	    scanf("%c", &x);
        fgets(i->address.state, 20, stdin);
	}

	printf("Employee List and Details.\n");
	int j=0;
	for(i=e; i<e+n; i++)
	{
	    printf("Employee %d:\n", ++j);
        display(i);
	}
}
