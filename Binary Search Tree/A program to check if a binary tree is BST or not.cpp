#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int key;
    struct node* left;
    struct node* right;
};
 
node *newNode(int item)
{
    node *temp =  new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}


bool isBST(node* root, node* l=NULL, node* r=NULL)
{
	if(root==NULL)
	{
		return true;
	}
	if(l!=NULL && root->key < l->key)
	{
		return false;
	}
	if(r!=NULL && root->key > r->key)
	{
		return false;
	}
	return isBST(root->left, l, root) and
           isBST(root->right, root, r);
}

int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
     
  getchar();
  return 0;
}  
