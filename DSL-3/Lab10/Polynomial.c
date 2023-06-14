#include<stdio.h>
#include<stdlib.h>

typedef struct Poly
{
    int coeff;
    int power;
    struct Poly* link;
}Poly;

void printPoly(Poly* p)
{
    Poly* temp=p;
    if(p==NULL)
        printf("List is empty.\n");
    else
    {
        printf("%dx^%d ", temp->coeff, temp->power);
        temp=temp->link;
        do
        {
            printf("%s%dx^%d ",temp->coeff>0?"+":"", temp->coeff, temp->power);
            temp=temp->link;
        }while(temp!=p);
        printf("\n");
    }
}

Poly* insert(Poly* p, int coeff, int power)
{
    Poly* temp=(Poly*)malloc(sizeof(Poly));
    Poly* new=(Poly*)malloc(sizeof(Poly));
    
    new->coeff=coeff;
    new->power=power;

    if(p==NULL)
    {
        p=(Poly*)malloc(sizeof(Poly));
        new->link=new;
        p=new;
    }
    else
    {
        new->link=p;

        temp=p;
        while(temp->link!=p)
            temp=temp->link;

        temp->link=new;    
    }
    return p;
}

int length(Poly* p)
{
    int length=0;
    Poly* temp=p;
    do 
    {
        length++;
        temp=temp->link;
    }while(temp!=p);

    return length;
}

Poly* AddSub(Poly* p1, Poly* p2, int d)
{
    if(p1==NULL) return p2;
    if(p2==NULL) return p1;

    Poly* temp1=p1;
    Poly* temp2=p2;
    Poly* result=NULL;
    int stop=0, c1=0, c2=0;

    do
    {
        if(temp1==p1 && c1!=0) break;
        if(temp2==p2 && c2!=0) break;
        if(temp1->power>temp2->power)
        {
            result=insert(result, temp1->coeff, temp1->power);
            temp1=temp1->link;
            c1++;
        }
        else if(temp1->power<temp2->power)
        {
            result=insert(result, temp2->coeff, temp2->power);
            temp2=temp2->link;
            c2++;
        }
        else
        {
            result=insert(result, d?(temp1->coeff+temp2->coeff):(temp1->coeff-temp2->coeff), temp1->power); 
            temp1=temp1->link;
            temp2=temp2->link;
            c1++; c2++;
        }
        stop++;
    }while((temp1!=p1 && temp2!=p2)||(temp1!=p1)||(temp2!=p2));

    do 
    {
        if(temp1!=p1)
        {
            result=insert(result, temp1->coeff, temp1->power);
            temp1=temp1->link;
            c1++;
        }
        if(temp2!=p2)
        {
            result=insert(result, temp2->coeff, temp2->power);
            temp2=temp2->link;
            c2++;
        }
    }while((temp1!=p1 && c1!=0) || (temp2!=p2 && c2!=0));

    return result;
}

Poly* multiplication(Poly* p1, Poly*p2)
{
    if(p1==NULL || p2==NULL) return NULL;

    Poly* temp1=p1;
    Poly* temp2=p2;
    Poly* multi=NULL;

    do
    {
        Poly* tempMulti=NULL;
        do
        {
            tempMulti=insert(tempMulti, temp1->coeff*temp2->coeff,
            temp1->power+temp2->power);
            temp2=temp2->link;
        }while(temp2!=p2);
        multi=AddSub(multi, tempMulti, 1);
        temp1=temp1->link;
    }while(temp1!=p1);

    return multi;
}

int main()
{
    Poly* p1=NULL; 
    Poly* p2=NULL;
    
    p1=insert(p1,45,5);
    p1=insert(p1,3,3);
    p1=insert(p1,4,1);
    p1=insert(p1,5,0);

    p2=insert(p2,13,3);
    p2=insert(p2,9,2);
    p2=insert(p2,7,1);
    p2=insert(p2,3,0);

    printf("\nPolynominal 1: ");
    printPoly(p1);
    printf("Polynomial 2: ");
    printPoly(p2);

    printf("\nAddition Result: \n");
    printPoly(AddSub(p1,p2,1));

    printf("\nSubtraction Result: \n");
    printPoly(AddSub(p1,p2,0));

    printf("\nMultiplication Result: \n");
    printPoly(multiplication(p1,p2));
}