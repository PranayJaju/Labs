#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* create()
{
	Node* p;
	int x;
	printf("Enter data.(-1 for no data): ");
	scanf("%d", &x);
	if(x==-1) return NULL;
	p=(Node*)malloc(sizeof(Node));
	p->data=x;

	printf("Enter left child of %d:\n", x);
	p->left=create();
	printf("Enter right child of %d:\n", x);
	p->right=create();

	return p;
}

void preorder(Node* root)
{
	if(root!=NULL)
	{
		printf("%d  ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d  ", root->data);
		inorder(root->right);
	}
}

void postorder(Node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d  ", root->data);
	}
}

int main()
{
	Node* root=NULL;
	root=create();
	printf("Preorder traversal: ");
	preorder(root);
	printf("\nInorder traversal: ");
	inorder(root);
	printf("\nPostorder traversal: ");
	postorder(root);
	printf("\n");
}