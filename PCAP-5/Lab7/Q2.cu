#include<stdio.h>

enum method_type{ROW, COL, ELE};

__global__ void MatrixMul(int *a, int *b, int *c, int row, int col, method_type method)
{
	int R = blockDim.y*blockIdx.y + threadIdx.y;
	int C = blockDim.x*blockIdx.x + threadIdx.x;

	switch(method)
	{
		case ROW:
			if(R >= row) return;
			for(int i = 0; i < col; i++)
			{
				int idx = R*col + i;
				c[idx] = 0;
				for(int k = 0; k < col; k++)
					c[idx] += a[R*col + k] * b[k*col + i];
			}
			break;

		case COL:
			if(C >= col) return;
			for(int i = 0; i < row; i++)
			{
				int idx = i*col + C;
				c[idx] = 0;
				for(int k = 0; k < row; k++)
					c[idx] += a[i*col + k] * b[k*col + C];
			}
			break;

		case ELE:
			if(R >= row || C >= col) return;
			c[R*col + C] = 0;
			for(int k = 0; k < col; k++)
				c[R*col + C] += a[R*col + k] * b[k*col + C];
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

	MatrixMul<<<grid, block>>>(da, db, dc, 3, 3, ELE);

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