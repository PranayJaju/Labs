#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"iSTACK.h"
int i;

int main()
{
	char prefix_exp[50];
	printf("Enter single digit prefix expression.\n");
	fgets(prefix_exp, 50, stdin);
	prefix_exp[strlen(prefix_exp)-1]='\0';

	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->stack=(int*)calloc(50, sizeof(int));
    s->top=-1;
    s->size=50;

    i=strlen(prefix_exp)-1;
    int op1, op2, res;
    while(i>=0)
    {
        char ch=prefix_exp[i];
        if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='^')
        	push(s, ch-'0');
        else
        {
        	op1=pop(s);
        	op2=pop(s);
        	switch(ch)
        	{
        		case '+': res=op1+op2;
        		break;
        		case '-': res=op1-op2;
        		break;
        		case '*': res=op1*op2;
        		break;
        		case '/': res=op1/op2;
        		break;
        		case '^': res=pow(op1,op2);
        		break;
        	}
        	push(s, res);
        }
        i--;
    }
    printf("Result: %d\n", s->stack[s->top]);
}