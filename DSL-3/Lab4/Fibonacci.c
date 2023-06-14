#include<stdio.h>
int Fibonacci(int n)
{
	if(n==0)
	return 0;
	if(n==1)
	return 1;
	else return Fibonacci(n-1)+Fibonacci(n-2);
}
void Print(int start, int n)
{
	if(start==n)
		return;
	printf("%d  ", Fibonacci(start));
	Print(start+1, n);
}
void main()
{
    int n;
	printf("Enter no.of terms.\n");
	scanf("%d", &n);
	Print(0, n);
}