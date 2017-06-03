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

int main()
{ 
    insert(1,1);
    insert(3,1);
    insert(1,1);
    insert(2,1);
    insert(1,1);
    printf("count of nodes is %d", totalLength(head));
    return 0;
}
