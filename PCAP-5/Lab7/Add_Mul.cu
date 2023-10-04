#include<stdio.h>

enum method_type{ROW, COL, ELE};
enum operation{ADD, MULTIPLY};

__device__ void Add(int *a, int *b, int *c, int idx)
{
	c[idx] = a[idx] + b[idx];
}

__device__ void Multiply(int *a, int *b, int *c, int row, int col, int nc)
{
	int idx = row*nc + col;
	c[idx] = 0;
	for(int k = 0; k < nc; k++)
		c[idx] += a[row*nc + k] * b[k*nc + col];
}

__global__ void MatrixOp(int *a, int *b, int*c, int row, int col, operation op, method_type method)
{
	int R = blockDim.y*blockIdx.y + threadIdx.y;
	int C = blockDim.x*blockIdx.x + threadIdx.x;

	switch(method)
	{
		case ROW:
			if(R >= row) return;
			for(int i = 0; i < col; i++)
			{
				if(op == ADD)
					Add(a, b, c, R*col + i);
				else if(op == MULTIPLY)
					Multiply(a, b, c, R, i, col);
			}
			break;

		case COL:
			if(C >= col) return;
			for(int i = 0; i < row; i++)
			{
				if(op == ADD)
					Add(a, b, c, i*col + C);
				else if(op == MULTIPLY)
					Multiply(a, b, c, i, C, col);
			}
			break;

		case ELE:
			if(R >= row || C >= col) return;
			if(op == ADD)
				Add(a, b, c, R*col + C);
			else if(op == MULTIPLY)
				Multiply(a, b, c, R, C, col);
			break;

		default:
			break;
	}
}

int main()
{
	int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int b[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
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

	MatrixOp<<<grid, block>>>(da, db, dc, 3, 3, ADD, ELE);

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