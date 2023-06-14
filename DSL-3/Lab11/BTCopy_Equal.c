#include<stdio.h>
#include<stdlib.h>

typedef struct btNode
{
    int data;
    struct btNode* left;
    struct btNode* right;
}btNode;

btNode* NewNode(int data)
{
    btNode* node=(btNode*)malloc(sizeof(btNode));
    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return node;
}

btNode* CopyBT(btNode* root)
{
    if(root==NULL) return NULL;

    btNode* newNode=NewNode(root->data);
    newNode->left=CopyBT(root->left);
    newNode->right=CopyBT(root->right);

    return newNode;
}

int EqualTrees(btNode* root1, btNode* root2)
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

void inorder(btNode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
		printf("%d  ", root->data);
		inorder(root->right);
    }
}

int main()
{
    btNode* root=NULL;
    root=NewNode(1);
    root->left=NewNode(2);
    root->left->left=NewNode(3);
    root->left->right=NewNode(4);
    root->right=NewNode(5);
    root->right->left=NewNode(6);
    root->right->right=NewNode(7);
    
    btNode* copy=CopyBT(root);
    printf("Inorder of original: ");
    inorder(root);
    printf("\nInorder of clone: ");
    inorder(copy);
    
    if(EqualTrees(root,copy))
    printf("\nEqual trees.\n");
    else printf("\nNot equal trees.\n");
}