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

void findPreSuc(node* root,node*& pre,node*& suc,int key)
{
	if(root == NULL)
	{
		return;
	}
	if(root->key == key)
	{
		if(root->left != NULL)
		{
			node* tmp = root->left;
			while(root->right != NULL)
			{
				tmp=tmp->right;
			}
			pre = tmp;
		}
		if(root->right != NULL)
		{
			node* tmp = root->right;
			while(root->left != NULL)
			{
				tmp=tmp->left;
			}
			pre = tmp;
		}
	}
	else
	{
		if(root->key > key)
		{
			suc = root;
			findPreSuc(root->left,pre,suc,key);
		}
		else
		{
			pre = root;
			findPreSuc(root->right,pre,suc,key);
		}
	}
}

int main()
{
    int key = 65;    //Key to be searched in BST
 
   /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
 
    node* pre = NULL, *suc = NULL;
 
    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
      cout << "Predecessor is " << pre->key << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->key;
    else
      cout << "No Successor";
    return 0;
}
