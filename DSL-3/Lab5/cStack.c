#include<stdio.h>
#include<stdlib.h>
#include"cSTACK.h"

int main()
{
    int n;
    printf("Enter stack size.\n");
    scanf("%d", &n);
    Stack* s=(Stack*)malloc(sizeof(Stack));
    (s->stack)=(char*)calloc(n, sizeof(char));
    s->size=n;
    s->top=-1;
    int action;
    do
    {
        printf("Enter action\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &action);
        if(action==1)
        {
            char ele;
            printf("Enter element to be pushed.\n");
            scanf(" %c", &ele);
            push(s, ele);
        }
        else if(action==2)
        {
            printf("Element popped: %c\n", pop(s));
        }
        else if(action==3)
        {
            printf("The stack is:\n");
            display(s);
        }
        else
        {
            printf("The stack is:\n");
            display(s);
            printf("Exiting...\n");
        }
    } while(action!=4);
}