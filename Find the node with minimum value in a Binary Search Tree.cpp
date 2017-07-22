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
 
node* insert(node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
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

int minValue(node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root->key;
}


int main()
{
  struct node* root = NULL;
  root = insert(root, 4);
  insert(root, 2);
  insert(root, 1);
  insert(root, 3);
  insert(root, 6);
  insert(root, 5);  
 
  printf("\n Minimum value in BST is %d", minValue(root));
  getchar();
  return 0;    
}
