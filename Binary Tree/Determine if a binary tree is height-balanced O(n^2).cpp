#include <bits/stdc++.h>
using namespace std; 

struct node
{
    int data;
    struct node* left, *right;
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

bool isBalanced(node* root)
{
	int lh = 0;
	int rh = 0;
	if(root == NULL)
	{
		return 1;
	}
	lh = height(root->left);
	rh = height(root->right);
	if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
	{
		return 1;
	}
	return 0;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
 
    if(isBalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");    
 
    getchar();
    return 0;
}
