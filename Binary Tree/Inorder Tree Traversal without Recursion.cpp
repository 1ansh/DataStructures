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

int inorder_wo_recursion(node* root)
{
	node* current = root;
	stack<node*> s;
	bool done= 0;
	while(!done)
	{
		if(current!=NULL)
		{
			s.push(current);
			current = current->left;
		}
		else
		{
			if(!(s.empty()))
			{
				current = s.top();
				s.pop();
				cout<<current->data<<" ";
				current = current->right;
			}
			else
			{
				done = 1;
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
 
  inorder_wo_recursion(root);
 
  getchar();
  return 0;
}
