#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cuda_runtime.h>

#define MAX_STR_LEN 1024

__global__ void SRS(char *S, char *RS, int strLen)
{
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    if(tid >= strLen) return;

    int startpos = 0;

    for(int i = 0; i < tid; i++) startpos += strLen - i;

    for(int i = startpos, j=0; j < strLen - tid; i++, j++)
        RS[i] = S[j];
}

int main() {
    char S[MAX_STR_LEN];
    char RS[MAX_STR_LEN];
    
    printf("Enter a string: ");
    fgets(S, MAX_STR_LEN, stdin);
    S[strlen(S)-1] = '\0';

    int strLen = strlen(S);
    int size = MAX_STR_LEN * sizeof(char);
    
    char *d_S, *d_RS;
    
    cudaMalloc((void**)&d_S, size);
    cudaMalloc((void**)&d_RS, size);
    
    cudaMemcpy(d_S, S, size, cudaMemcpyHostToDevice);
    
    int numBlocks = (strLen + 255) / 256; // Adjust block size according to your needs
    SRS<<<numBlocks, 256>>>(d_S, d_RS, strLen);
    
    cudaMemcpy(RS, d_RS, size, cudaMemcpyDeviceToHost);
    
    //RS[strLen*(strLen-1)] = '\0'; // Null-terminate RS
    
    printf("S: %s\n", S);
    printf("RS: %s\n", RS);
    
    cudaFree(d_S);
    cudaFree(d_RS);
    
    return 0;
}