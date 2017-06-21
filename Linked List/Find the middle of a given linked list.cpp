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

void midElementM1() //Method 1
{
	Node* temp=head;
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		count+=1;
	}
	int i=0;
	temp=head;
	
	while(i<count/2)
	{
		temp=temp->next;
		i++;
	}
	cout<<"Mid Element=  "<<temp->data<<endl;
}

void midElementM2() // Method 2
{
	Node *fast=head, *slow=head;
	if(head!=NULL)
	{
		while(fast!=NULL && fast->next!=NULL)
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		cout<<"Mid Element=  "<<slow->data<<endl;
	}
}

void midElementM3() // Method 3
{
	Node *mid=head,*temp=head;
	int count=1;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
		if(count%2!=0)
		{
			mid=mid->next;
		}
	}
	cout<<"Mid Element=  "<<mid->data<<endl;
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
	midElementM1();
	midElementM2();
	midElementM3();
}

