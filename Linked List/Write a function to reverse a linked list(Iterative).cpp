#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
Node* head;

void insert(int x,int position)
{
	Node* temp;
	temp=new Node();
	temp->data=x;
	if(position==1)
	{
		temp->next=head;
		head=temp;
		return;
	}
	else
	{
		Node* temp2=head;
		for(int i=0;i<position-2;i++)
		{
			temp2=temp2->next;
		}
		temp->next=temp2->next;
		temp2->next=temp;
	}
}

void reverseIterative()
{
	Node *curr=head,*prev=NULL,*agla=head;
	while(curr!=NULL)
	{
		agla=curr->next;
		curr->next=prev;
		prev=curr;
		curr=agla;
	}
	head=prev;
}

void print()
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

int main()
{
	head=NULL;
	int x,position,n,i;
	cout<<"Enter the numbers of element you want to insert:  ";
	cin>>n;
	for(i=0;i<n;i++)
	{
	    cout<<"Enter the data:  ";
	    cin>>x;
		cout<<"Enter the position:  ";
		cin>>position;
		insert(x,position);
	}
	print();
	reverseIterative();
	print();
}

