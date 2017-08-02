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

int getLeafCount(node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	if(root->left==NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return (getLeafCount(root->left) + getLeafCount(root->right));
	}
}

int main()
{
  /*create a tree*/ 
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);    
   
  /*get leaf count of the above created tree*/
  printf("Leaf count of the tree is %d", getLeafCount(root));
   
  getchar();
  return 0;
}
