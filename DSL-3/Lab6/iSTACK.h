typedef struct
{
    int* stack;
    int top;
    int size;
}Stack;

int isFull(Stack* s)
{
    return s->top==s->size-1;
}

int isEmpty(Stack *s)
{
    return s->top==-1;
}

void push(Stack* s, int x)
{
    if(isFull(s))
    printf("---Stack Overflow---\n");
    else
    s->stack[++(s->top)]=x;
}

int pop(Stack* s)
{
    if(isEmpty(s))
    {
        printf("---Stack Underflow---\n");
        return -9999;
    }
    else
    return s->stack[(s->top)--];
}

void display(Stack* s)
{
    if(isEmpty(s))
    printf("Stack is empty.\n");
    else
    {
        for(int i=s->top; i>=0; i--)
        printf("%d\n", s->stack[i]);
    }
}