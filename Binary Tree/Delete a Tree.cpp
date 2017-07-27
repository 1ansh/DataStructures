#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{
    struct node* node = (struct node*)
                           malloc(sizeof(struct node));
 
    node->data = data;
    node->left = NULL;
    node->right = NULL;  
    return(node);
}

void deleteTree(node* root)
{
	if(root ==NULL)
	{
		return;
	}
	deleteTree(root->left);
	deleteTree(root->right);
	cout<<"Delete Node: "<<root->data<<endl;
	delete(root);
}


int main()
{
    struct node *root = newNode(1); 
    root->left            = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right   = newNode(5); 
   
    deleteTree(root);  
    root = NULL;
 
    printf("\nTree deleted ");
   
    getchar();
    return 0;
}
