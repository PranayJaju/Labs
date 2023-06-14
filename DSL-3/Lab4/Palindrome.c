#include<stdio.h>
#include<string.h>
int isPalindrome(char s[], int leftindex, int rightindex)
{
    if(leftindex==rightindex)
    return 1;
	if(s[leftindex]!=s[rightindex])
	return -1;
	isPalindrome(s, leftindex+1, rightindex-1);
}
void main()
{
	char s[50];
	printf("Enter a string.\n");
	scanf("%s", s);
	int check=isPalindrome(s, 0, strlen(s)-1);
	if(check==1)
	printf("Is Palindrome.\n");
	else
	printf("Is not Palindrome.\n");
}