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

int totalLength(Node* head)
{
	if(head==NULL)
	{
		return 0;
	}
	else
	{
		return 1+totalLength(head->next);
	}
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

void NthFromEndM1(int n) // Method 1
{
	int i,l;
	Node *temp=head;
	l=totalLength(temp);
	for(i=0;i<l-n;i++)
	{
		temp=temp->next;
	}
	cout<<n<<"th element from end=  "<<temp->data<<endl;
}

void NthFromEndM2(int n) // Method 2
{
	int i,l;
	Node *temp=head,*temp1=head;
	for(i=0;i<n;i++)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		temp=temp->next;
		temp1=temp1->next;
	}
	cout<<n<<"th element from end=  "<<temp1->data<<endl;
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
	cout<<"Enter position from end:  ";
	int val;
	cin>>val;
	NthFromEndM1(val);
	NthFromEndM2(val);
}

