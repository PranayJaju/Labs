#include<stdio.h>
#include<stdlib.h>

int GCD_ConInt(int m, int n)
{
	int t=n>m?m:n;
	while(t>0)
	{
		if(m%t==0 && n%t==0)
			return t;
		t=t-1;
	}
	return 1;
}

int main()
{
	int n, m;
	printf("Enter 2 numbers.\n");
	scanf("%d %d", &n, &m);
	printf("GCD of %d and %d using Consecutive Integer Method: %d\n", n, m, GCD_ConInt(n,m));
}