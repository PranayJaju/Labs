#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"iSTACK.h"
int i, j;

int main()
{
    char prefix_exp[50], postfix_exp[50];
	printf("Enter single digit prefix expression.\n");
	fgets(prefix_exp, 50, stdin);
	prefix_exp[strlen(prefix_exp)-1]='\0';

	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->stack=(int*)calloc(50, sizeof(int));
    s->top=-1;
    s->size=50;

    i=strlen(prefix_exp)-1; j=0;
    int op1, op2;
    while(i>=0)
    {
        char ch=prefix_exp[i];
        if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='^')
        	push(s, ch-'0');
        else
        {
            if(j==0)
            {
        	    op1=pop(s);
        	    op2=pop(s);
                postfix_exp[j++]=(char)'0'+op1;
                postfix_exp[j++]=(char)'0'+op2;
                postfix_exp[j++]=ch;
            }
            else
            {
                op1=pop(s);
                postfix_exp[j++]=(char)'0'+op1;
                postfix_exp[j++]=ch;
            }
        }
        i--;
        for(int k=0; k<j; k++)
        printf("%c", postfix_exp[k]);
        printf("\n");
    }
    postfix_exp[j]='\0';
    printf("Postfix Expression: %s\n", postfix_exp);
}