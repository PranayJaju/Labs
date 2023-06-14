#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cSTACK.h"
int i, j;

int main()
{
    char input_string[50]; char palin_check[50];
    Stack* s=(Stack*)malloc(sizeof(Stack));
    s->stack=(char*)calloc(75, sizeof(char));
    s->size=75;
    s->top=-1;
    printf("Enter a string.\n");
    fgets(input_string, 50, stdin);
    input_string[strlen(input_string)-1]='\0';

    for(i=0; i<strlen(input_string); i++)
        push(s, input_string[i]);

    for(i=s->top, j=0; i>=0; i--, j++)
        palin_check[j]=pop(s);
    palin_check[j]='\0';

    if(strcmp(input_string, palin_check)==0)
        printf("Palindrome.\n");
    else
        printf("Not Palindrome.\n");    
}