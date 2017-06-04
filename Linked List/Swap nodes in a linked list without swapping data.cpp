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

void swap(int x,int y)
{
	if(x==y)
	{
		return;
	}
	Node *temp1=head,*temp2=head,*prevx=NULL,*prevy=NULL,*temp3;
	while(temp1 && temp1->data!=x)
	{
		prevx=temp1;
		temp1=temp1->next;
	}
	while(temp2 && temp2->data!=y)
	{
		prevy=temp2;
		temp2=temp2->next;
	}
	if(temp1==NULL||temp2==NULL)
	{
		return;
	}
	if(prevx!=NULL)
	{
		prevx->next=temp2;	
	}
	else
	{
		head=temp2;
	}
	if(prevy!=NULL)
	{
		prevy->next=temp1;	
	}
	else
	{
		head=temp2;
	}
	temp3=temp1->next;
	temp1->next=temp2->next;
	temp2->next=temp3;
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
	swap(2,4);
	print();
}

