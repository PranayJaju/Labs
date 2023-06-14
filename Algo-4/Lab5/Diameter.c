#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
    return a>b?a:b;
}

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

int diameter(BST* root, int* dia)
{
    int lh=0, rh=0;
    int ld=0, rd=0;

    if(root==NULL) return 0;

    ld=diameter(root->left, &lh);
    rd=diameter(root->right, &rh);
    *dia=max(lh,rh)+1;

    return max(lh+rh+1, max(ld, rd));
}

int main()
{
    BST* root=NULL;
    root=insert(root,50);
    int arr[]={30,20,70,40,60,80,90};
    for(int i=0; i<7; i++)
        insert(root,arr[i]);

    int dia=0;
    dia=diameter(root,&dia);

    printf("Diameter of the tree: %d\n", dia);
}