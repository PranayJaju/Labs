#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int day;
    int *month;
    int year;
}DOB;
typedef struct
{
    int reg_no;
    char *name;
    char address[50];
}STU_INFO;
typedef struct
{
    char *college_name;
    char university_name[50];
}COLLEGE;
typedef struct 
{
    DOB date;
    STU_INFO si;
    COLLEGE c;
}STUDENT;

int main()
{
    char ch;
    STUDENT *student;
	student = (STUDENT *) calloc(1, sizeof(STUDENT));
	student->date.month = (int *) calloc(1, sizeof(int));
	student->si.name = (char *) calloc(50, sizeof(char));
	student->c.college_name = (char *) calloc(50, sizeof(char));

    printf("Enter Student Name, Registration Number and Address: \n");
    fgets(student->si.name, 50, stdin);
	scanf("%d", &(student->si.reg_no));
    scanf("%c", &ch);
    fgets(student->si.address, 50, stdin);
	
	printf("Enter Date of Birth(dd/mm/yyyy): \n");
	scanf("%d %d %d", &(student->date.day), student->date.month, &(student->date.year));
	
	printf("Enter College and University Name: \n");
    scanf("%c", &ch);
    fgets(student->c.college_name, 50, stdin);
    fgets(student->c.university_name, 50, stdin);

	printf("***************\n");

	printf("Student: %sRegistration number: %d\nAddress: %s\n", student->si.name, student->si.reg_no, student->si.address);
	printf("Student is born on %02d/%02d/%02d\n", student->date.day, *student->date.month, student->date.year);
    printf("College: %s", student->c.college_name);
	printf("University: %s", student->c.university_name);

	return 0;
}
