typedef struct
{
    int* stack;
    int top1;
    int top2;
    int size;
}Stack;

int isFull(Stack* s)
{
    return s->top1==s->top2-1;
}


void push1(Stack* s, int x)
{
    if(isFull(s))
    printf("---Stack Overflow---\n");
    else
    s->stack[++(s->top1)]=x;
}

void push2(Stack* s, int x)
{
    if(isFull(s))
    printf("---Stack Overflow---\n");
    else
    s->stack[--(s->top2)]=x;
}

int pop1(Stack* s)
{
    if(s->top1==-1)
    {
        printf("---Stack 1 Underflow---\n");
        return -9999;
    }
    else
    return s->stack[(s->top1)--];
}

int pop2(Stack* s)
{
    if(s->top2==s->size-1)
    {
        printf("---Stack 2 Underflow---\n");
        return -9999;
    }
    else
    return s->stack[(s->top2)++];
}

void display1(Stack* s)
{
    if(s->top1==-1)
    printf("Stack is empty.\n");
    else
    {
        for(int i=s->top1; i>=0; i--)
        printf("%d\n", s->stack[i]);
    }
}

void display2(Stack* s)
{
    if(s->top2==s->size-1)
    printf("Stack is empty.\n");
    else
    {
        for(int i=s->top2; i<s->size; i++)
        printf("%d\n", s->stack[i]);
    }
}