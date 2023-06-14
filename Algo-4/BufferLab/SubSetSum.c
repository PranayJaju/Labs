#include<stdio.h>
#include<stdlib.h>

int SubsetSum(int a[], int n, int sum)
{
	if(sum==0) return 1; //this means that subset having sum s/2 has been subtracted from the set
	if(n==0) return 0; //all elements have been exhausted. No sol exists 

	return SubsetSum(a, n-1, sum) || SubsetSum(a, n-1, sum-a[n-1]);
}

int main()
{
	int a[]={2,4,8,8,2};
	int sum=0;
	for(int i=0; i<5; i++)
		sum+=a[i];

	if(sum%2==1) printf("Not Possible.\n");
	else printf("%sPossible.\n", SubsetSum(a, 5, sum/2)?"":"Not ");
}