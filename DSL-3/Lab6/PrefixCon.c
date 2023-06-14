#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cSTACK.h"
int i, j;

int precedence(char op)
{
    if(op=='(')
    	return 0;
    if(op=='+' || op=='-')
    	return 1;
    if(op=='*' || op=='/')
    	return 2;
    else
    	return 3;
}

int main()
{
	char input_exp[50], exp[50];
	printf("Enter an expression.\n");
	fgets(input_exp, 50, stdin);
	input_exp[strlen(input_exp)-1]='\0';
	for(i=strlen(input_exp)-1, j=0; i>=0; i--, j++)
	{
		if(input_exp[i]=='(')
			exp[j]=')';
		else if(input_exp[i]==')')
			exp[j]='(';
		else
		    exp[j]=input_exp[i];
	}
	exp[j]='\0';

	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->stack=(char*)calloc(75, sizeof(char));
    s->top=-1;
    s->size=75;

    char prefix_exp[50], postfix[50], popped;

    push(s, '(');

    i=0, j=0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
        	push(s, '(');

        else if(exp[i]==')')
        {
        	while((popped=pop(s))!='(')
        		postfix[j++]=popped;
        }

        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')
        {
        	while(precedence(exp[i])<=precedence(s->stack[s->top]) && s->stack[s->top]!='(')
        		postfix[j++]=pop(s);
        	push(s, exp[i]);
        }

        else
        	postfix[j++]=exp[i];
        i++;
    }

    while(s->stack[s->top]!='(')
    	postfix[j++]=pop(s);
    postfix[j]='\0';

    for(i=strlen(postfix)-1, j=0; i>=0; i--, j++)
	{
		if(postfix[i]=='(')
		    prefix_exp[j]=')';
		else if(postfix[i]==')')
		    prefix_exp[j]='(';
		else
		       prefix_exp[j]=postfix[i];
	}
    prefix_exp[j]='\0';

    printf("%s\n", prefix_exp);
}