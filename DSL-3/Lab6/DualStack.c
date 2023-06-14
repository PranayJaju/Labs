#include<stdio.h>
#include<stdlib.h>
#include"dualSTACK.h"

int main()
{
    int n;
    printf("Enter stack size.\n");
    scanf("%d", &n);
    Stack* s=(Stack*)malloc(sizeof(Stack));
    (s->stack)=(int*)calloc(n, sizeof(int));
    s->size=n;
    s->top1=-1;
    s->top2=n;
    int action;
    do
    {
        printf("Enter action\n");
        printf("1.Push1\t\t2.Push2\n3.Pop1\t\t4.Pop2\n");
        printf("5.Display1\t6.Display2\n7.Exit\n");
        scanf("%d", &action);
        if(action==1)
        {
            int ele;
            printf("Enter element to be pushed.\n");
            scanf(" %d", &ele);
            push1(s, ele);
        }
        else if(action==2)
        {
            int ele;
            printf("Enter element to be pushed.\n");
            scanf(" %d", &ele);
            push2(s, ele);
        }
        else if(action==3)
        {
            printf("Element popped: %d\n", pop1(s));
        }
        else if(action==4)
        {
            printf("Element popped: %d\n", pop2(s));
        }
        else if(action==5)
        {
            printf("The stack is:\n");
            display1(s);
        }
        else if(action==6)
        {
            printf("The stack is:\n");
            display2(s);
        }
        else
        {
            printf("The stack 1 is:\n");
            display1(s);
            printf("The stack 2 is:\n");
            display2(s);
            printf("Exiting...\n");
        }
    } while(action!=7);
}