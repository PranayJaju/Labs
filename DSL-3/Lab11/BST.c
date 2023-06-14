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

BST* maxValueNode(BST* root)
{
    BST* current=root;
    while(current && current->right!=NULL)
        current=current->right;
    return current;
}

BST* deleteNode(BST* root, int key)
{
    if(root==NULL) return root;
    if(key<root->data) deleteNode(root->left,key);
    else if(key>root->data) deleteNode(root->right,key);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            root=NULL;
            return NULL;
        }
        if(root->left==NULL)
        {
            BST* temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL)
        {
            BST* temp=root->left;
            free(root);
            return temp;
        }

        BST* temp=maxValueNode(root->left);
        root->data=temp->data;
        root->left=deleteNode(root->left,temp->data);
    }
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

int main()
{
    /*
              50
            /    \
           30    70
          /  \  /   \
         20  40 60  80
    */
    BST* root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,70);
    insert(root,40);
    insert(root,60);
    insert(root,80);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    if(search(root,45)==NULL)
        printf("Element %d not in given BST.\n",45);
    else printf("Element %d in given BST.\n",45);

    printf("Delete 20.\n");
    root=deleteNode(root,20);
    inorder(root);
    printf("\n");

    printf("Delete 70.\n");
    root=deleteNode(root,70);
    inorder(root);
    printf("\n");

    printf("Delete 50.\n");
    root=deleteNode(root,50);
    inorder(root);
    printf("\n");
}