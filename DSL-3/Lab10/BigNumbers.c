#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CircularDLL.h"

Node* addition(Node* Num1, Node* Num2)
{
    Node* temp1=Num1, *temp2=Num2;
    Node* result=NULL;
    int carry=0, sum;

    do
    {
        sum=temp1->data+temp2->data+carry;
        carry=sum>=10?1:0;
        sum=sum%10;

        result=insert(result,sum,0);
        
        temp1=temp1->next;
        temp2=temp2->next;
    }while(temp1!=Num1 && temp2!=Num2);

    while(temp1!=Num1)
    {
        sum=temp1->data+carry;
        carry=sum>=10?1:0;
        sum=sum%10;

        result=insert(result,sum,0);

        temp1=temp1->next;
    }

    while(temp2!=Num2)
    {
        sum=temp2->data+carry;
        carry=sum>=10?1:0;
        sum=sum%10;

        result=insert(result,sum,0);

        temp2=temp2->next;
    }
    if(carry==1) result=insert(result,1,0);
    return result;
}

int main()
{
    char num1[15], num2[15];
    printf("Enter 2 numbers.\n");
    scanf("%s", num1);
    scanf("%s", num2);

    Node* Num1=NULL, *Num2=NULL;

    for(int i=strlen(num1)-1; i>=0; i--)
        Num1=insert(Num1,num1[i]-'0',-1);
    printf("First number: ");
    printListLast(Num1);

    for(int i=strlen(num2)-1; i>=0; i--)
        Num2=insert(Num2,num2[i]-'0',-1);
    printf("Second number: ");
    printListLast(Num2);

    printf("Addition Result: ");
    printList(addition(Num1,Num2));
}