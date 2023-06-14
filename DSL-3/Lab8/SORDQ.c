#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 8

typedef struct
{
    char dq[size][size];
    int l, r;
}DQ;

void insertLeft(DQ* d, char x[8])
{
    if(d->l>0)
    {
        strcpy(d->dq[--d->l], x);
        return;
    }
    if(d->r==size)
    {
        printf("DQ is full.\n");
        return;
    }
    for(int i=d->r ; i>0; i--) strcpy(d->dq[i],d->dq[i-1]);
    d->r++;
    strcpy(d->dq[0],x);
}

void insertRight(DQ* d, char x[8])
{
    if(d->r<size)
    {
        strcpy(d->dq[d->r++],x);
        return;
    }
    if(d->l==0)
    {
        printf("DQ is full.\n");
        return;
    }
    for(int i=d->l; i<=size; i++) strcpy(d->dq[i-1],d->dq[i]);
    d->l--;
    strcpy(d->dq[size-1],x);
}

char* deleteLeft(DQ* d)
{
    if(d->l == d->r) 
    { 
        printf("Queue is empty\n"); 
        return NULL; 
    }
    return d->dq[d->l++];
}

void display(DQ *d) 
{
    for(int i=0; i<size; i++)
    {
        if(i>=d->l && i<d->r) printf("%s ", d->dq[i]);
        else printf("_ ");
    }    
    printf("\n");
}

int main()
{
    DQ *d=(DQ*)malloc(sizeof(DQ));
    d->l=0; d->r=0;

    insertRight(d, "abc");
    insertRight(d, "xyz");
    insertRight(d, "pqr");
    display(d);

    insertLeft(d, "lmn");
    insertLeft(d, "ijk");
    display(d);

    deleteLeft(d);
    deleteLeft(d);
    deleteLeft(d);
    display(d);
    printf("\n");
}