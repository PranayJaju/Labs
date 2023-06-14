#include<stdio.h>
#include<stdlib.h>

#define size 7

typedef struct
{
    int dq[size];
    int l, r;
}DQ;

void insertLeft(DQ* d, int x)
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

void insertRight(DQ* d, int x)
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

int deleteLeft(DQ* d)
{
    if(d->l == d->r) 
    { 
        printf("Queue is empty\n"); 
        return -1; 
    }
    return d->dq[d->l++];
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

int main()
{
    DQ *d=(DQ*)malloc(sizeof(DQ));
    d->l=0; d->r=0;

    insertRight(d, 82);
    insertRight(d, 45);
    insertRight(d, 69);
    display(d);

    insertLeft(d, 12);
    insertLeft(d, 1);
    display(d);

    deleteLeft(d);
    deleteLeft(d);
    deleteLeft(d);
    display(d);
    printf("\n");
}