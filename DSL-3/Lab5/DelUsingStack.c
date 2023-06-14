#include<stdio.h>
#include<stdlib.h>
#include"iSTACK.h"
int i;

int main()
{
    Stack* s=(Stack*)malloc(sizeof(Stack));
    s->stack=(int*)calloc(20, sizeof(int));
    s->size=20;
    s->top=-1;
    
    int n, k;
    printf("Enter no.of elements.\n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements.\n");
    for(i=0; i<n; i++) scanf("%d", &arr[i]);

    printf("Enter no.of elements to be deleted.\n");
    scanf("%d", &k);

    for(i=0; i<n; i++)
    {
        if(s->top==-1 || arr[i]<=s->stack[s->top] || k==0)
            push(s, arr[i]);
        else
        {
            pop(s);
            k--; i--;
        }
    }

    display(s);
}