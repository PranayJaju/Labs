#include<stdio.h>
char* copy(char *s1, char *s2)
{
	if(*s1!='\0')
	{
		*s2=*s1;
		copy(++s1, ++s2);
	}
    return s2+'\0';
}
void main()
{
	char s1[50], s2[50];
	printf("Enter a string.\n");
	fgets(s1, 50, stdin);
	printf("String 1: %s", s1);
	copy(s1, s2);

	printf("String 2 after copying: %s", s2);
}