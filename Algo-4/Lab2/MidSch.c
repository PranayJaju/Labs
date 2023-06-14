#include<stdio.h>
#include<stdlib.h>

int isPrime(int n)
{ 
	int c=0;
	for(int i=2; i<n; i++)
	{
		if(n%i==0)
		c++;
	}
	if(c>1)
	return 0;
	return 1;
}

int main()
{
	int n, m;
	printf("Enter 2 numbers.\n");
	scanf("%d%d", &n, &m);
	int a=n; int b=m;
	int small=a>b?b:a;
	int gcd=1;
	for(int i=2; i<=small; i++)
	{
		if(isPrime(i) && a%i==0 && b%i==0)
		{
			gcd*=i;
			a=a/i;
			b=b/i;
			i--;
		}
	}
	printf("GCD of %d and %d using Middle School Method is: %d\n", n, m, gcd);
}