#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *next;
};


Node* addToEmpty(Node* last,int x)
{
	if(last!=NULL)
	{
		return last;
	}
	Node* temp=new Node();
	temp->data=x;
	last=temp;
	last->next=last;
	return last;
}

Node* addBegin(Node* last,int x)
{
	if(last==NULL)
	{
		return addToEmpty(last,x);
	}
	Node* temp=new Node();
	temp->data=x;
	temp->next=last->next;
	last->next=temp;
	return last;
}

Node* addEnd(Node* last,int x)
{
	if(last==NULL)
	{
		return addToEmpty(last,x);
	}
	Node* temp=new Node();
	temp->data=x;
	temp->next=last->next;
	last->next=temp;
	last=temp;
	return last;
}

Node* addAfter(Node* last,int x,int item)
{
	if(last==NULL)
	{
		return last;
	}
	Node *temp,*p;
	temp->data=x;
	p=last->next;
	do
	{
		if(p->data==item)
		{
			temp->next=p->next;
			p->next=temp;
			if(p==last)
			{
				last==temp;
			}
			return last;
		}	
		p=p->next;
	}while(p!=last->next);
	cout << item << " not present in the list." << endl;
	return last;	
}

void traverse(Node* last)
{
	if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
	Node* temp=last->next;
	while(temp!=last)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<last->data<<" ";
}

int main()
{
    struct Node *last = NULL;
 
    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);
 
    traverse(last);
 
    return 0;
}
