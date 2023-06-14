#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CharDQ.h"

int isPal(char *s)
{
    DQ *d = (DQ*)malloc(sizeof(DQ));
    d->l=0; d->r=0;
    int i;
    
    for(i=0; i<strlen(s)/2; i++) 
    insertRight(d, s[i]);
    i += strlen(s)%2;

    for(; i<strlen(s); i++) 
    {
        if(s[i] != deleteRight(d)) 
        {
            free(d);
            return 0;
        }
    }
    free(d);
    return 1;
}

int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);

    printf("%s is %sa Palindrome\n", s, isPal(s)?"":"not ");
    return 0;
}
