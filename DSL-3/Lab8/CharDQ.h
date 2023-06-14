#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 50

typedef struct
{
    char dq[size];
    int l, r;
}DQ;

void insertLeft(DQ* d, char x)
{
    if(d->l>0)
    {
        d->dq[--d->l]=x;
        return;
    }
    if(d->r==size)
    {
        printf("DQ is full.\n");
        return;
    }
    for(int i=d->r ; i>0; i--) d->dq[i]=d->dq[i-1];
    d->r++;
    d->dq[0]=x;
}

void insertRight(DQ* d, char x)
{
    if(d->r<size)
    {
        d->dq[d->r++]=x;
        return;
    }
    if(d->l==0)
    {
        printf("DQ is full.\n");
        return;
    }
    for(int i=d->l; i<=size; i++) d->dq[i-1] = d->dq[i];
    d->l--;
    d->dq[size-1]=x;
}

char deleteLeft(DQ* d)
{
    if(d->l == d->r) 
    { 
        printf("Queue is empty\n"); 
        return -1; 
    }
    return d->dq[d->l++];
}

char deleteRight(DQ* d)
{
    if(d->l == d->r) 
    { 
        printf("Queue is empty\n"); 
        return -1; 
    }
    return d->dq[--d->r];
}

void display(DQ *d) 
{
    for(int i=0; i<size; i++)
    {
        if(i>=d->l && i<d->r) printf("%d ", d->dq[i]);
        else printf("x ");
    }    
    printf("\n");
}