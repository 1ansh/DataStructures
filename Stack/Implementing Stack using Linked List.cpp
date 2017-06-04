#include<bits/stdc++.h>
using namespace std;
 
#define MAX 1000

struct StackNode
{
	int data;
	StackNode* next;
};

int isEmpty(struct StackNode *root)
{
    return !root;
}

StackNode* getNewNode(int x)
{
	StackNode* temp=new StackNode();
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void push(StackNode** root,int x)
{
	StackNode* New=getNewNode(x);
	New->next=*root;
	*root=New;
	printf("%d pushed to stack\n", x);
}

int pop(StackNode** root)
{
	if(isEmpty(*root))
	{
		return INT_MIN;
	}
	else
	{
		StackNode* temp=*root;
		*root=temp->next;
		int popped=temp->data;
		delete temp;
		return popped;
	}
}

int peek(StackNode* root)
{
	return(root->data);
}


int main()
{
    struct StackNode* root = NULL;
 
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    printf("%d popped from stack\n", pop(&root));
 
    printf("Top element is %d\n", peek(root));
 
    return 0;
}

