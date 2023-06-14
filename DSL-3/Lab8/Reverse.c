#include<stdio.h>
#include<stdlib.h>
#include"CircularQueue.h"

void reverse(Queue* q) 
{
    if(q->front==q->rear) return;
    int a=dequeue(q);
    reverse(q);
    enqueue(q, a);
}

int main()
{
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->queue=(int*)calloc(10, sizeof(int));
    q->front=-1; q->rear=-1;
    q->size=10;

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    display(q);

    reverse(q);
    display(q);
}