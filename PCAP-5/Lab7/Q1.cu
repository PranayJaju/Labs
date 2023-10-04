#include<stdio.h>

enum method_type{ROW, COL, ELE};

__global__ void MatrixAdd(int *a, int *b, int *c, int row, int col, method_type method)
{
	int R = blockDim.y*blockIdx.y + threadIdx.y;
	int C = blockDim.x*blockIdx.x + threadIdx.x;

	switch(method)
	{
		case ROW:
			if(R >= row) return;
			for(int i = 0; i < col; i++)
				c[R*col + i] = a[R*row + i] + b[R*row + i];
			break;

		case COL:
			if(C >= col) return;
			for(int i = 0; i < row; i++)
				c[i*col + C] = a[i*col + C] + b[i*col + C];
			break;

		case ELE:
			if(R >= row || C >= col) return;
			c[R*col + C] = a[R*col + C] + b[R*col + C];
			break;

		default:
			break;
	}
}

int main()
{
	int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int b[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
	int c[3][3];

	int *da, *db, *dc;
	int size = 3*3*sizeof(int);

	cudaMalloc(&da, size);
	cudaMalloc(&db, size);
	cudaMalloc(&dc, size);

	cudaMemcpy(da, a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(db, b, size, cudaMemcpyHostToDevice);

	dim3 grid(1,1,1);
	dim3 block(5,5,1);

	MatrixAdd<<<grid, block>>>(da, db, dc, 3, 3, ELE);

	cudaMemcpy(c, dc, size, cudaMemcpyDeviceToHost);

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			printf("%d  ", c[i][j]);
		printf("\n");
	}

	cudaFree(da);
	cudaFree(db);
	cudaFree(dc);
}