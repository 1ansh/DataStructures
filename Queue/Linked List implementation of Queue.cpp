#include <bits/stdc++.h>
using namespace std;

struct QNode
{
	int data;
	QNode *next;	
};
QNode *front=NULL;
QNode *rear=NULL;
void Enqueue(int x)
{
	QNode *temp;
	temp=new QNode();
	temp->data=x;
	temp->next=NULL;
	if(front==NULL && rear==NULL)
	{
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}

void Dequeue()
{
	if(front==NULL && rear==NULL)
	{
		cout<<"ERROR"<<endl;
		return;
	}
	if(front==rear)
	{
		front=rear=NULL;
		return;
	}
	else
	{
		QNode *temp=front;
		front=front->next;
		free(temp);
	}
}
void Front()
{
	if(front==NULL)
	{
		cout<<"ERROR"<<endl;
		return;
	}
	else
	{
		cout<<front->data<<endl;
	}
}

void printQueue()
{
	QNode* temp=front;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	Front();
	Enqueue(2);printQueue();
	Enqueue(4);printQueue();
	Enqueue(5);printQueue();
	Enqueue(6);printQueue();
	Enqueue(7);printQueue();
	Enqueue(9);printQueue();
	Dequeue();printQueue();
	Dequeue();printQueue();
	Dequeue();printQueue();
	Front();
}
