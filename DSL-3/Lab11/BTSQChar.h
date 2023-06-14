typedef struct btNode
{
    char data;
    struct btNode* left;
    struct btNode* right;
}btNode;

typedef struct
{
    btNode* stack[20];
    int top;
}Stack;

typedef struct 
{
    btNode* queue[20];
    int front; int rear;
}Queue;

int StackFull(Stack* s)
{
    return s->top==19;
}

int StackEmpty(Stack *s)
{
    return s->top==-1;
}

void push(Stack* s, btNode* bt)
{
    if(StackFull(s))
    printf("---Stack Overflow---\n");
    else
    s->stack[++(s->top)]=bt;
}

btNode* pop(Stack* s)
{
    if(StackEmpty(s))
    {
        printf("---Stack Underflow---\n");
        return NULL;
    }
    else
    return s->stack[(s->top)--];
}

int QueueFull(Queue* q)
{
    return q->rear==19;
}

int QueueEmpty(Queue* q)
{
    return q->front==q->rear;
}

void enqueue(Queue* q, btNode* bt)
{
    if(QueueFull(q))
    printf("Queue is full.\n");
    else
    q->queue[++(q->rear)]=bt;
}

btNode* dequeue(Queue* q)
{
    if(QueueEmpty(q))
    {
        printf("Queue is empty.\n");
        return NULL;
    }
    else
    return q->queue[++(q->front)];
}