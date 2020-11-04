#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left,*right;
	Node(int data)
	{
		this->data=data;
		left=right=NULL;
	} 
};

void printPostorder(struct Node *node)
{
	if(node==NULL)
	{
		return;
	}
	printPostorder(node->left);
	printPostorder(node->right);
	cout<<node->data<<" ";
}
void printPreorder(struct Node *node)
{
	if(node==NULL)
	{
		return;
	}
	cout<<node->data<<" ";
	printPreorder(node->left);
	printPreorder(node->right);
	
}
void printInorder(struct Node *node)
{
	if(node==NULL)
	{
		return;
	}
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
	
}
/*
	1
       / \
      2   3
     / \
    4   5
*/	
int main()
{
	struct Node *root = new Node(1); 
   	root->left        = new Node(2); 
	root->right       = new Node(3); 
	root->left->left  = new Node(4); 
	root->left->right = new Node(5);
	printPostorder(root); //4 5 2 3 1 
	cout<<endl;
        printPreorder(root);  //1 2 4 5 3
	cout<<endl;
	printInorder(root);   //4 2 5 1 3 
	cout<<endl;
}
