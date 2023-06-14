#include<stdio.h>
#include<stdlib.h>
#include"iSTACK.h"

void Display(Stack* s)
{
    if(isEmpty(s))
    printf("0\n");
    else
    {
        for(int i=s->top; i>=0; i--)
        printf("%d", s->stack[i]);
    }
}

int main()
{
    Stack* s=(Stack*)malloc(sizeof(Stack));
    (s->stack)=(int*)calloc(30, sizeof(int));
    s->size=30;
    s->top=-1;
    int n, N;
    printf("Enter a number.\n");
    scanf("%d", &n);
    N=n;
    while(N>0)
    {
        push(s, N%2);
        N/=2;
    }
    printf("Binary of %d: ", n);
    Display(s);
    printf("\n");
}