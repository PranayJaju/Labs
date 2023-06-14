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
    return (q->rear==q->size-1 && q->front==0)||(q->front==q->rear+1);
}

int isEmpty(Queue* q)
{
    return q->front==-1;
}

void enqueue(Queue* q, int x)
{
    if(isFull(q))
    printf("Queue is full.\n");
    else
    {
        if(q->front==-1) q->front=0;
        q->rear=(q->rear+1)%(q->size);
        q->queue[q->rear]=x;
    }
}

int dequeue(Queue* q)
{
    int element;
    if(isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -9999;
    }
    else
    {
        element=q->queue[q->front];
        q->front=(q->front+1)%(q->size);
        return element;
    }
}

void display(Queue* q)
{
    if(isEmpty(q))
    printf("Queue is empty.\n");
    else
    {
        if(q->front<q->rear)
        {
            for(int i=q->front; i<=q->rear; i++)
            printf("%d  ", q->queue[i]);
            printf("\n");
        }
        else
        {
            //index 0 to last
            for(int i=0; i<=q->rear; i++)//write this as 2nd loop for front to rear display
            printf("%d  ", q->queue[i]);
            for(int i=q->front; i<q->size; i++)
            printf("%d  ", q->queue[i]);
            printf("\n");
        }
    }
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