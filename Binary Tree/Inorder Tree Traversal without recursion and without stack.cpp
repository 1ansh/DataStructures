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

void MorrisTraversal(node* root)
{
	node* current = root;
	node* pre;
	current = root;
	if(root == NULL)
	{
		return;
	}
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			cout<<current->data<<" ";
			current = current->right;  
		}
		else
		{
			pre = current->left;
      		while(pre->right != NULL && pre->right != current)
      		{
      			 pre = pre->right;	
			}
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			}
		}
	}
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
 
  MorrisTraversal(root);
 
  getchar();
  return 0;
}
