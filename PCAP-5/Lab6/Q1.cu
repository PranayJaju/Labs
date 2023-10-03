#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<cuda_runtime.h>

#define MAX_SEN_LEN 1024
#define MAX_WORD_LEN 64
#define MAX_BLOCKS 1024
#define THREADS_PER_BLOCK 1024

__global__ void countWordOccurrences(char *sen, char *word, int *count, int senLen, int wordLen)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;

    while(idx < senLen)
    {
        int match = 1;
        for (int i = 0; i < wordLen; i++)
            if (sen[idx + i] != word[i])
            {
                match = 0;
                break;
            }

        if (match == 1)
        {
            if((sen[idx+wordLen] == ' ' || idx == senLen-wordLen) && sen[idx-1] == ' ')
            	atomicAdd(count, 1);
            idx += wordLen;
        } 
        else
            idx += blockDim.x;
    }
}

int main() {
    char sen[MAX_SEN_LEN];
    char word[MAX_WORD_LEN];
    int count = 0;
    
    printf("Enter a sen: ");
    fgets(sen, sizeof(sen), stdin);
    sen[strlen(sen)-1] = '\0';
    
    printf("Enter the target word to count: ");
    scanf("%s", word);
    
    int senLen = strlen(sen);
    int wordLen = strlen(word);
    
    char *d_sen, *d_word;
    int *d_count;
    
    cudaMalloc((void**)&d_sen, senLen);
    cudaMalloc((void**)&d_word, wordLen);
    cudaMalloc((void**)&d_count, sizeof(int));
    
    cudaMemcpy(d_sen, sen, senLen, cudaMemcpyHostToDevice);
    cudaMemcpy(d_word, word, wordLen, cudaMemcpyHostToDevice);
    cudaMemcpy(d_count, &count, sizeof(int), cudaMemcpyHostToDevice);
    
    int numBlocks = (senLen + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;
    
    countWordOccurrences<<<numBlocks, THREADS_PER_BLOCK>>>(d_sen, d_word, d_count, senLen, wordLen);
    
    cudaMemcpy(&count, d_count, sizeof(int), cudaMemcpyDeviceToHost);
    
    printf("The word '%s' appeared %d times in the sen.\n", word, count);
    
    cudaFree(d_sen);
    cudaFree(d_word);
    cudaFree(d_count);
}