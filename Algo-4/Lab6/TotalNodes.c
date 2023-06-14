#include<stdio.h>
#include<stdlib.h>
#include"BST.h"

int NoOfNodes=0;
int opCount=0;

void TotalNodes(BST* root)
{
	opCount++;
	if(root!=NULL)
	{
		NoOfNodes++;
		TotalNodes(root->left);
		TotalNodes(root->right);
	}
}

int main()
{
	int data;
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

    TotalNodes(root);
    printf("Total no.of nodes: %d\n", NoOfNodes);
    printf("OpCount: %d\n", opCount);
}