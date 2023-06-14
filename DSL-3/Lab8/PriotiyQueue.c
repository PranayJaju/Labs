#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int queue[8];
    int rear;
    int front;
}PQueue;

void enqueue(PQueue* pq, int x)
{
    if(pq->rear==8)
    printf("PQueue is full.\n");
    else
    {
        int k;
        for(k=pq->front; k<pq->rear; k++)
            if(pq->queue[k]>x) break;

        for(int i=pq->rear; i>=k; i--) 
            pq->queue[i+1]=pq->queue[i];
    
        pq->rear++;
        pq->queue[k]=x;
    }
}

int dequeue(PQueue* pq)
{
    if(pq->front>=pq->rear)
    {
        printf("PQueue is empty.\n");
        return -9999;
    }
    else
    return pq->queue[++(pq->front)];
}

void display(PQueue* pq)
{
    if(pq->front>=pq->rear)
    printf("PQueue is empty.\n");
    else
    for(int i=pq->front; i<pq->rear; i++)
    printf("%d  ", pq->queue[i]);
    printf("\n");
}

int main()
{
    PQueue* pq=(PQueue*)malloc(sizeof(PQueue));
    pq->front=0; pq->rear=0;

    enqueue(pq, 45);
    enqueue(pq, 23);
    enqueue(pq, 78);
    enqueue(pq, 190);
    enqueue(pq, 6);

    printf("Queue in ascending order: ");
    display(pq);

    dequeue(pq);
    dequeue(pq);
    enqueue(pq, 69);
    enqueue(pq, 13);

    printf("Queue in ascending order: ");
    display(pq);
}