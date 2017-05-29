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

void deleteByPosition(int position)
{
	Node* temp=head;
	if(position==1)
	{
		head=temp->next;
		delete temp;
	}
	else
	{
		for(int i=0;i<position-2;i++)
		{
			temp=temp->next;
		}
		Node* temp2=temp->next;
		temp->next=temp2->next;
		delete temp2;
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

int main()
{
	head=NULL;
	int x,position,insert_n,delete_n,i,key;
	cout<<"Enter the numbers of element you want to insert:  ";
	cin>>insert_n;
	for(i=0;i<insert_n;i++)
	{
	    cout<<"Enter the data:  ";
	    cin>>x;
		cout<<"Enter the position:  ";
		cin>>position;
		insert(x,position);
		print();
	}
	cout<<"Enter the numbers of element you want to delete:  ";
	cin>>delete_n;
	for(i=0;i<delete_n;i++)
	{
	    cout<<"Enter the position:  ";
	    cin>>key;
		deleteByPosition(key);
		print();
	}
}

