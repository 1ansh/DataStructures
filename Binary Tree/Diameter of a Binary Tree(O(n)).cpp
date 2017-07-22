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

int diameterOPT(node* root, int* height)
{
	int lh=0,rh=0;
	int ldiam=0,rdiam=0;
	if(root == NULL)
	{
		*height = 0;
		return 0;
	}
	ldiam = diameterOPT(root->left,&lh);
	rdiam = diameterOPT(root->right,&rh);
	*height = max(lh,rh) +1;
	
	return max(1+lh+rh,max(ldiam,rdiam));
}

int main()
{
 
  /* Constructed binary tree is 
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  int height;
  printf("Diameter of the given binary tree is %d\n", diameterOPT(root, &height));
 
  getchar();
  return 0;
}
