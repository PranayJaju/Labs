typedef struct btNode
{
    int data;
    struct btNode* left;
    struct btNode* right;
}btNode;

typedef struct
{
    btNode* stack[10];
    int top;
}Stack;

int isFull(Stack* s)
{
    return s->top==9;
}

int isEmpty(Stack *s)
{
    return s->top==-1;
}

void push(Stack* s, btNode* bt)
{
    if(isFull(s))
    printf("---Stack Overflow---\n");
    else
    s->stack[++(s->top)]=bt;
}

btNode* pop(Stack* s)
{
    if(isEmpty(s))
    {
        printf("---Stack Underflow---\n");
        return NULL;
    }
    else
    return s->stack[(s->top)--];
}