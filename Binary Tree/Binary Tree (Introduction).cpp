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
	node *temp=new node();
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
}

int main()
{
  /*create root*/
  struct node *root = newNode(1);  
  /* following is the tree after above statement 
 
        1
      /   \
     NULL  NULL  
  */
   
 
  root->left        = newNode(2);
  root->right       = newNode(3);
  /* 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
  */
 
 
  root->left->left  = newNode(4);
  /* 4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
   4    NULL  NULL  NULL
  /  \
NULL NULL
*/
 
  return 0;
}

