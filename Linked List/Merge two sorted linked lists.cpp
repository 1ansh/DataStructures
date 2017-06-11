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
    /* Start with the empty list */
    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;
 
    /* Let us create two sorted linked lists to test
      the functions
       Created lists, a: 5->10->15,  b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
 
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
 
    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);
 
    printf("Merged Linked List is: \n");
    printList(res);
    return 0;
}
