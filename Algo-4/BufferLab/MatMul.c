#include<stdio.h>
#include<stdlib.h>

int main()
{
    int p,q,x,y;
	printf("Enter order of Matrix 1.\n");
	scanf("%d%d", &p, &q);
	printf("Enter order of Matrix 2.\n");
	scanf("%d%d", &x, &y);
	if(q!=x)
	    printf("Matrix Multiplication not possible.\n");
	else
	{
	    int m1[p][q], m2[x][y], m[p][y];
	    int i,j,k; int opcount=0;
	   
	    printf("Enter Mat 1 elements.\n");
	    for(i=0; i<p; i++)
	        for(j=0; j<q; j++)
	            scanf("%d", &m1[i][j]);
	    
	    printf("Enter Mat 2 elements.\n");
	    for(i=0; i<x; i++)
	        for(j=0; j<y; j++)
	            scanf("%d", &m2[i][j]);       

        for(i=0; i<p; i++)
            for(j=0; j<y; j++)
            {
            	m[i][j]=0;
                for(k=0; k<q; k++)
                {
                	opcount++;
                    m[i][j]+=m1[i][k]*m2[k][j];
                }
            }
        
        printf("Matrix Product:\n");  
        for(i=0; i<p; i++)
        {
        	for(j=0; j<y; j++)
		        printf("%d  " , m[i][j]);
	        printf("\n");
        }
        printf("Opcount: %d\n", opcount);  
	}    
}