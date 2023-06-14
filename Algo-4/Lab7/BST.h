#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
    int data; 
    struct BST* left;
    struct BST* right;
}BST;

BST* NewNode(int data)
{
    BST* node=(BST*)malloc(sizeof(BST));
    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return node;
}

BST* insert(BST* root, int key)
{
    if(root==NULL) return NewNode(key);

    if(key<root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    
    return root;
}

BST* search(BST* root, int key)
{
    if(root==NULL || root->data==key)
        return root;
    if(key<root->data) return search(root->left,key);
    if(key>root->data) return search(root->right,key);
    else return NULL;
}

BST* CopyTree(BST* root)
{
    if(root==NULL) return NULL;

    BST* newNode=NewNode(root->data);
    newNode->left=CopyTree(root->left);
    newNode->right=CopyTree(root->right);

    return newNode;
}

int EqualTrees(BST* root1, BST* root2)
{
    if(root1==NULL && root2==NULL) return 1;
    if(root1!=NULL && root2!=NULL)
    {
        return (root1->data==root2->data)&&
               (EqualTrees(root1->left,root2->left))&&
               (EqualTrees(root1->right,root2->right));
    }
    return 0;
}

void inorder(BST* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
		printf("%d  ", root->data);
		inorder(root->right);
    }
}

void preorder(BST* root)
{
	if(root!=NULL)
	{
		printf("%d  ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(BST* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ", root->data);
    }
}