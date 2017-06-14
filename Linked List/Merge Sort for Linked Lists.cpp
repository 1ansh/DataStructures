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

Node* SortedMerge(Node* head1,Node* head2)
{
	Node* res=NULL;
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data<=head2->data)
		{
			push_back(&res,head1->data);
			head1=head1->next;
		}
		else
		{
			push_back(&res,head2->data);
			head2=head2->next;
		}
	}
	while(head1!=NULL)
	{
		push_back(&res,head1->data);
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		push_back(&res,head2->data);
		head2=head2->next;
	}
	return res;
}

void FrontBackSplit(Node* source,Node** frontRef,Node** backRef)
{
	Node* fast;
	Node* slow;
	if(source==NULL || source->next==NULL)
	{
		*frontRef=source;
		*backRef=NULL;
	}
	else
	{
		slow=source;
		fast =source->next;
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast!=NULL)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}
		*frontRef=source;
		*backRef=slow->next;
		slow->next=NULL;
	}
}

void MergeSort(Node** headRef)
{
	Node* head=*headRef,*a,*b;
	if ((head == NULL) || (head->next == NULL))
	{
		return;
	}
	FrontBackSplit(head, &a, &b); 
	MergeSort(&a);
	MergeSort(&b);
	*headRef = SortedMerge(a, b);
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



int main()
{
  struct Node* a = NULL;
  
  push(&a, 15);
  push(&a, 10);
  push(&a, 5); 
  push(&a, 20);
  push(&a, 3);
  push(&a, 2); 
  
  cout<<"Entered Linked List:"<<endl;
  printList(a);
  
  MergeSort(&a);
  
  printf("Sorted Linked List is: \n");
  printList(a);           
  
  return 0;
}
