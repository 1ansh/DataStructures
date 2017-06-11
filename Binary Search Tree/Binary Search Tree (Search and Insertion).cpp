#include <iostream>
using namespace std;


struct node
{
	int data;
	node *left;
	node *right;
};

node* newNode(int x)
{
	node* temp=new node();
	temp->data=x;
	temp->right=NULL;
	temp->right=NULL;
	return temp;
}
node* insertNode(node* root,int x)
{
	if(root==NULL)
	{
		return newNode(x);
	}
	else
	{
		if(x<=root->data)
		{
			root->left=insertNode(root->left,x);
		}
		else if(x>root->data)
		{
			root->right=insertNode(root->right,x);
		}
		return root;
	}
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
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
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
  
    // print inoder traversal of the BST
    inorder(root);
  
    return 0;
}

