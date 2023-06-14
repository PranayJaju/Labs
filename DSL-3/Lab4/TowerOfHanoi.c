#include<stdio.h>
int toh(int n, char from_rod, char aux_rod, char to_rod)
{
	static int moves=0;
	if(n==0) return moves;
	toh(n-1, from_rod, to_rod, aux_rod);
	printf("Move disc %d from rod %c to rod %c.\n", n, from_rod, to_rod);
	moves++;
	toh(n-1, aux_rod, from_rod, to_rod);
}
void main()
{
	int n, num_moves;
	printf("Enter no.of discs.\n");
	scanf("%d", &n);
	printf("\n");
    num_moves=toh(n, 'A', 'B', 'C');
    printf("\n");
    printf("No.of moves: %d\n", num_moves);
}