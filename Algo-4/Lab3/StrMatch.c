#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[50], ch[50];
	printf("Enter a string.\n");
	fgets(str, 50, stdin);
	str[strlen(str)-1]='\0';

	printf("Enter characters to be checked.\n");
	fgets(ch, 50, stdin);
	ch[strlen(ch)-1]='\0';

	int flag=1; int opcount=0;

	for(int i=0; i<strlen(str); i++)
	{
		flag=1;
		for(int j=0; j<strlen(ch); j++)
		{
			opcount++;
			if(ch[j]!=str[i+j])
			{
				flag=0;
				break;
			}
			if(j==strlen(ch)-1)
				printf("String matched at position: %d\n", i+1);
		}
		if(flag==1) break;
	}
	if(flag==0) printf("String not matched.\n");

	printf("Opcount: %d\n", opcount);
}