#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int* queue;
    int rear;
    int front;
    int size;
}Queue;

int isFull(Queue* q)
{
    return q->rear==q->size-1;
}

int isEmpty(Queue* q)
{
    return q->front>=q->rear;
}

void enqueue(Queue* q, int x)
{
    if(isFull(q))
    printf("Queue is full.\n");
    else
    q->queue[++(q->rear)]=x;
}

int dequeue(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -9999;
    }
    else
    return q->queue[++(q->front)];
}

void display(Queue* q)
{
    if(isEmpty(q))
    printf("Queue is empty.\n");
    else
    for(int i=q->front+1; i<=q->rear; i++)
    printf("%d  ", q->queue[i]);
    printf("\n");
}