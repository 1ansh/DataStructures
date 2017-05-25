#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	struct Node *next; 	
};

void printList(struct Node *n)
{
	while(n!=NULL)
	{
		cout<<n->data<<endl;
		n=n->next;	
	}	
}

int main()
{
		struct Node* head=NULL;
		struct Node* second=NULL;
		struct Node* third=NULL;
		
//		dynamic memory allocation
		head = new Node(); //first method to allot dynamic memory
 		second = (struct Node*)malloc(sizeof(struct Node)); //second method to allot dynamic memory
  		third = (struct Node*)malloc(sizeof(struct Node));
  		
  		head->data=1;
  		head->next=second;
  		second->data=2;
  		second->next=third;
  		third->data=3;
  		third->next=NULL;
  		
  		printList(head);
}

