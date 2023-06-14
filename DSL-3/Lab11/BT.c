#include<stdio.h>
#include<stdlib.h>
#include"BTStackQueue.h"

btNode* create()
{
	btNode* p;
	int x;
	printf("Enter data.(-1 for no data): ");
	scanf("%d", &x);
	if(x==-1) return NULL;
	p=(btNode*)malloc(sizeof(btNode));
	p->data=x;

	printf("Enter left child of %d:\n", x);
	p->left=create();
	printf("Enter right child of %d:\n", x);
	p->right=create();

	return p;
}

void Preorder(btNode* root)
{
    if(root==NULL) return;
	btNode* current;
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->top=-1;
    push(s,root);

    while(!StackEmpty(s))
    {
    	current=pop(s);
    	printf("%d  ", current->data);
    	if(current->right!=NULL) push(s, current->right);
    	if(current->left!=NULL) push(s, current->left);
    }
}

void Inorder(btNode* root)
{
    if(root==NULL) return;
	btNode* current=root;
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->top=-1;

	while(!StackEmpty(s) || current!=NULL)
	{
		if(current!=NULL)
		{
			push(s, current);
			current=current->left;
		}
		else
		{
			current=pop(s);
			printf("%d  ", current->data);
			current=current->right;
		}
	}
}

void Postorder(btNode* root)
{
    if(root==NULL) return;
	btNode* current=root;
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->top=-1;	

	do
    {
        while(root)
        {
            if(root->right) push(s,root->right);
            push(s, root);
            root=root->left;
        }
        root=pop(s);
        if(root->right && s->stack[s->top]==root->right)
        {
            pop(s);
            push(s,root);
            root=root->right;
        }
        else
        {
            printf("%d  ",root->data);
            root=NULL;
        }
    } while (!StackEmpty(s));
}

void Levelorder(btNode* root)
{
    if(root==NULL) return;
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->front=-1; q->rear=-1;

    enqueue(q,root);
    while(!QueueEmpty(q))
    {
        btNode* current=dequeue(q);
        printf("%d  ", current->data);
        if(current->left!=NULL) enqueue(q, current->left);
        if(current->right!=NULL) enqueue(q, current->right);
    }
}

int main()
{
	btNode* root=NULL;
	root=create();
	printf("Preorder traversal: ");
	Preorder(root);
	printf("\nInorder traversal: ");
	Inorder(root);
    printf("\nPostorder traversal: ");
    Postorder(root);
    printf("\nLevelorder traversal: ");
    Levelorder(root);
}