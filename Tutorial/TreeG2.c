#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
}TNode;
TNode *insertNode(TNode *node,int n)
{
	TNode *new1;
	if(node==NULL)
	{
		new1=(TNode *)malloc(sizeof(TNode));
		new1->data=n;
		new1->left=new1->right=NULL;
		return new1;
	}
	else
	{
		if(n<node->data)
			node->left=insertNode(node->left,n);
		else
			node->right=insertNode(node->right,n);
	}
	return node;
}
TNode *createTree()
{
	char ch;
	TNode *pr=NULL;
	int n;
	do{
		printf("\nEnter value for new node: ");
		scanf("%d",&n);
		if(pr==NULL)
		  pr=insertNode(pr,n);
		else
		  insertNode(pr,n);
		printf("\ndo you want to create more node: ");
		scanf(" %c",&ch);
	}while(ch=='Y'||ch=='y');
	return pr;
}
void traverseInorder(TNode *root)
{
	if(root!=NULL)
	{
		traverseInorder(root->left);
		printf("%d ",root->data);
		traverseInorder(root->right);
	}
}
void traversePreorder(TNode *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		traversePreorder(root->left);
		traversePreorder(root->right);
	}
}
void traversePostorder(TNode *root)
{
	if(root!=NULL)
	{
		traversePostorder(root->left);
		traversePostorder(root->right);
		printf("%d ",root->data);
	}
}
int findSize(TNode *root)
{
	if(root==NULL)
		return 0;
	else
		return 1+findSize(root->left)+findSize(root->right);
}
int findMin(TNode *root)
{
	while(root->left!=NULL)
	     root=root->left;
	return root->data;
}
int findMax(TNode *root)
{
	while(root->right!=NULL)
	     root=root->right;
	return root->data;
}
void findMirror(TNode *node)
{
	TNode *temp;
	if(node==NULL)
		return;
	findMirror(node->left);
	findMirror(node->right);
	temp=node->left;
	node->left=node->right;
	node->right=temp;
}
int findDepth(TNode *node)
{
	if(node==NULL)
		return 0;
	else
	{
		int ld=findDepth(node->left);
		int rd=findDepth(node->right);
		if(ld>rd)
			return ld+1;
		else
			return rd+1;
	}
}
int main()
{
	TNode *root=NULL;
	int ch,n;
	do{
		printf("\n1. Create Tree");
		printf("\n2. Insert Node");
		printf("\n3. In-Order");
		printf("\n4. Pre-Order");
		printf("\n5. Post-Order");
		printf("\n6. Find Size");
		printf("\n7. Find Min");
		printf("\n8. Find Max");
		printf("\n9. Find Mirror");
		printf("\n10. Find Depth");
		printf("\n20. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: root=createTree();
					break;
			case 2:	printf("\nEnter value to insert: ");
					scanf("%d",&n);
					insertNode(root,n);
					break;
			case 3: traverseInorder(root);
					break;
			case 4: traversePreorder(root);
					break;
			case 5: traversePostorder(root);
					break;
			case 6: n=findSize(root);
					printf("\nNo of nodes: %d",n);
					break;
			case 7: printf("\nMin Value: %d",findMin(root));
					break;
			case 8: printf("\nMax Value: %d",findMax(root));
					break;
			case 9: findMirror(root);
					traverseInorder(root);
					break;
			case 10:n=findDepth(root);
					printf("\nDepth of the tree: %d",n-1);
					break;
			case 20: printf("Exiting from program");
					  break;
			default: printf("\nwrong choice");
		}
	}while(ch!=20);
}
