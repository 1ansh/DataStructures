#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};



void push_back(Node** head,int x)
{
	Node* temp;
	temp=new Node();
	temp->data=x;
	temp->next=NULL;
	if(*head==NULL)
	{
		*head=temp;
		return;
	}
	Node* temp2=*head;
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	temp2->next=temp;
}


void push(Node** head,int x)
{
	Node* temp;
	temp=new Node();
	temp->data=x;
	temp->next=*head;
	*head=temp;
}

void printList(Node* head)
{
	Node* temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}


Node* reverse(Node *head,int k)
{
	Node *curr=head,*prev=NULL,*agla=head;
	int temp=0;
	while(curr!=NULL && temp<k)
	{
		agla=curr->next;
		curr->next=prev;
		prev=curr;
		curr=agla;
		temp++;
	}
	if(agla!=NULL)
	{
		head->next=reverse(agla,k);
	}
	return prev;
}

int main(void)
{
    struct Node* head = NULL;
  
     push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);           
 
     printf("\nGiven linked list \n");
     printList(head);
     head = reverse(head, 3);
 
     printf("\nReversed Linked list \n");
     printList(head);
 
     return(0);
}
