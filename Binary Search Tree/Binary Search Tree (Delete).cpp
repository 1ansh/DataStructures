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

node* minValueNode(node* root)
{
	if(root == NULL)
	{
		return root;
	}
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;
}

node* deleteNode(node* root,int key)
{
	if(root == NULL)
	{
		return root;
	}
	if(root->key < key)
	{
		root->right=deleteNode(root->right,key);
	}
	else if(root->key > key)
	{
		root->left=deleteNode(root->left,key);
	}
	else
	{
		if(root->left==NULL)
		{
			node* tmp = root->right;
			free(root);
			return tmp;
		}
		if(root->right==NULL)
		{
			node* tmp = root->left;
			free(root);
			return tmp;
		}
		struct node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    return 0;
}
