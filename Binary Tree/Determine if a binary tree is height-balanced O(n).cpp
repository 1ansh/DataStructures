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

bool isBalanced(node* root,int* height)
{
	int lh = 0,l=0;
	int rh = 0,r=0;
	if(root == NULL)
	{
		*height = 0;
		return 1;
	}
	l = isBalanced(root->left,&lh);
	r = isBalanced(root->right,&rh);
	
	*height = max(lh,rh)+1;
	if(lh - rh >=2 || rh - lh >=2)
	{
		return 0;
	}
	else return l&&r;
}

int main()
{
  int height = 0;
    
  /* Constructed binary tree is
             1
           /   \
         2      3
       /  \    /
     4     5  6
    /
   7
  */   
  struct node *root = newNode(1);  
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);
 
  if(isBalanced(root, &height))
    printf("Tree is balanced");
  else
    printf("Tree is not balanced");    
 
  getchar();
  return 0;
}
