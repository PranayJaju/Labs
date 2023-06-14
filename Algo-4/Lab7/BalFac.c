#include<stdio.h>
#include<stdlib.h>
#include"BST.h"

//int max(int a, int b)
//{
//    return a>b?a:b;
//}

void BalanceFactor(BST* root, int* height)
{
    int lh=0, rh=0; // left and right height of current node

    if(root==NULL) return;

    BalanceFactor(root->left, &lh);
    BalanceFactor(root->right, &rh);
    *height=lh>rh?lh:rh +1;

    printf("Balance Factor of %d: %d\n", root->data, lh-rh);
}

int main()
{
	int data; int height;
	BST* root=NULL;

	printf("Enter nodes of tree.(-1 for termination)\n");
	while(1)
	{
		scanf("%d", &data);
		if(data==-1) break;
		root=insert(root, data);
	}

    //root=insert(root,50);
    //int arr[]={30,20,70,40,60,80,90};
    //for(int i=0; i<sizeof(arr)/sizeof(int); i++)
    //    root=insert(root,arr[i]);

    BalanceFactor(root, &height);
}