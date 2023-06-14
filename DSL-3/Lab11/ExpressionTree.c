#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"BTSQChar.h"

btNode* NewNode(char data)
{
    btNode* node=(btNode*)malloc(sizeof(btNode));
    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return node;
}

void inorder(btNode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
		printf("%c  ", root->data);
		inorder(root->right);
    }
}

char* prefixExpTree(btNode** p, char* prefix)
{
    if(*prefix=='\0') return NULL;

    while(1)
    {
        char* q=NULL;
        if(*p==NULL) *p=NewNode(*prefix);
        else
        {
            if((*prefix>='A' && *prefix<='Z')||
               (*prefix>='a' && *prefix<='z')||
               (*prefix>='0' && *prefix<='9')) return prefix;

            q=prefixExpTree(&(*p)->left, prefix+1);
            q=prefixExpTree(&(*p)->right, q+1);

            return q;
        }
    }
}

btNode* postfixExpTree()
{
    char postfix[50];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    btNode* x,*y,*z;
    Stack* s=(Stack*)malloc(sizeof(Stack));
    for(int i=0; i<strlen(postfix); i++)
    {
        if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||
           postfix[i]=='/'||postfix[i]=='^')
        {
            z=NewNode(postfix[i]);
            x=pop(s);
            y=pop(s);
            z->left=y;
            z->right=x;
            push(s,z);
        }
        else push(s,NewNode(postfix[i]));
    }

    return z;
}

int EvalExpTree(btNode* root)
{
    if(!root) return 0;
    
    if(!root->left && !root->right)
    return root->data-'0';
    
    int leftValue=EvalExpTree(root->left);
    int rightValue=EvalExpTree(root->right);

    if(root->data=='+')
    return leftValue+rightValue;
    else if(root->data=='-')
    return leftValue-rightValue;
    else if(root->data=='*')
    return leftValue*rightValue;
    else if(root->data=='/')
    return leftValue/rightValue;
    else
    return pow(leftValue,rightValue);
}

int main()
{
    char prefix[50];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    btNode* tree1=NULL;
    prefixExpTree(&tree1,prefix);
    printf("Infix expression: ");
    inorder(tree1);
    printf("\n");

    btNode* tree2=postfixExpTree();
    printf("Infix expression: ");
    inorder(tree2);
    printf("\n");

    printf("Evaluation of tree 1: %d\n", EvalExpTree(tree1));
    printf("Evaluation of tree 2: %d", EvalExpTree(tree2));
}