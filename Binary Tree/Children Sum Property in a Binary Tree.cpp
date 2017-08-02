#include <bits/stdc++.h>
using namespace std; 

struct node
{
    int data;
    struct node* left;
	node* right;
};

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
int max(int a, int b)
{
  return (a >= b)? a: b;
}

int height(node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return(1+max(height(root->left),height(root->right)));
}

bool isSumProperty(node* root)
{
	int left_data=0,right_data=0;
	if(root == NULL || (root->left == NULL && root->right==NULL))
	{
		return 1;
	}
	if(root->left)
	{
		left_data = root->left->data;
	}
	if(root->right)
	{
		right_data = root->right->data;
	}
	
	
	if(root->data == left_data+right_data && isSumProperty(root->left) && isSumProperty(root->right))
	{
		return 1;
	}
	return 0;
}

int main()
{
  struct node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  if(isSumProperty(root))
    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");
 
  getchar();
  return 0;
}
