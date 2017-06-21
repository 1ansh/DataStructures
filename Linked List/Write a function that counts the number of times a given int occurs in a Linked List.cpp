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

void countFreq(int val)
{
	Node* temp=head;
	int count=0;
	while(temp!=NULL)
	{
		if(temp->data==val)
		{
			count+=1;
		}
		temp=temp->next;
	}
	cout<<val<<" occurs "<<count<<" times.";
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
	cout<<"Enter the element whose frequency is to be calculated:  ";
	int val;
	cin>>val;
	countFreq(val);
}

