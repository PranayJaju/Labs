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

int main()
{
    int n;
    printf("Enter Queue size.\n");
    scanf("%d", &n);
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->queue=(int*)calloc(n, sizeof(int));
    q->front=-1;
    q->rear=-1;
    q->size=n;
    int action;
    do
    {
        printf("Enter action\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &action);
        if(action==1)
        {
            int x;
            printf("Enter element to be pushed.\n");
            scanf("%d", &x);
            enqueue(q, x);
        }
        else if(action==2)
        {
            printf("Element removed: %d\n", dequeue(q));
        }
        else if(action==3)
        {
            printf("The queue is:\n");
            display(q);
        }
        else
        {
            printf("The queue is:\n");
            display(q);
            printf("Exiting...\n");
        }
    } while(action!=4);
}