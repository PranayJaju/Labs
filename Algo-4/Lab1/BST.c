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

int main()
{
    BST* root=NULL;
    root=insert(root,50);
    int arr[]={30,20,70,40,60,80};
    for(int i=0; i<6; i++)
    	insert(root,arr[i]);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    if(search(root,45)==NULL)
    {
        printf("Element %d not in given BST.\n",45);
        insert(root,45);
        printf("Element %d inserted into the BST.\n",45);
    }
    else printf("Element %d is in given BST.\n",45);

    printf("Inorder: ");
    inorder(root);
    printf("\n");
}