#include<stdio.h>
#include<stdlib.h>

int opcount=0;

int Fib(int n)
{
	opcount++;
	if(n==1) return 0;
    if(n==2) return 1;
	return Fib(n-1)+Fib(n-2);
}

int main()
{
	int n;
	printf("Enter nth term to be computed.\n");
	scanf("%d", &n);
	printf("Nth Fibonacci term: %d\n", Fib(n));
	printf("Opcount: %d\n", opcount);
}