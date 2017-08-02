#include <bits/stdc++.h>
using namespace std; 

struct node
{
    int data;
    node* left; 
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

void iterativePreorder(node* root)
{
	if(root == NULL)
	{
		return;
	}
	stack<node*> s;
	s.push(root);
	while(!(s.empty()))
	{
		node* curr = s.top();
		cout<<curr->data<<" ";
		s.pop();
		if(curr->right)
		{
			s.push(curr->right);
		}
		if(curr->left)
		{
			s.push(curr->left);
		}
	}
}

int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  iterativePreorder(root);
  return 0;
}
