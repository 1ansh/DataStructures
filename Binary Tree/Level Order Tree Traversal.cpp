#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;


struct node
{
	int data;
	node *left,*right;	
};

node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return(Node);
}

void printLevelOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* current=q.front();
		cout<<current->data<<" ";
		if(current->left!=NULL){
			q.push(current->left);
		}
		if(current->right!=NULL){
			q.push(current->right);
		}
		q.pop();
	}
}
 
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
 
    return 0;
}
