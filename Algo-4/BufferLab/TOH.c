#include<stdio.h>
#include<stdlib.h>

int opcount=0;

void toh(int n, char from_rod, char aux_rod, char to_rod)
{
	if(n==0) return;
	toh(n-1, from_rod, to_rod, aux_rod);
	printf("Disc %d: %c -> %c.\n", n, from_rod, to_rod);
	opcount++;
	toh(n-1, aux_rod, from_rod, to_rod);
}
void main()
{
	int n;
	printf("Enter no.of discs.\n");
	scanf("%d", &n);
	printf("\n");
    toh(n, 'A', 'B', 'C');
    printf("\n");
    printf("Opcount: %d\n", opcount);
}
