#include <bits/stdc++.h>
using namespace std;
#define MAX 101

class Queue
{
	private:
		int A[MAX],front,rear;
	public:
		Queue()
		{
			front=-1;rear=-1;	
		}
		bool isEmpty()
		{
			return(front==-1&&rear==-1);
		}
		bool isFull()
		{
			return (rear+1)%MAX==front?true:false;
		}
		void Enqueue(int x)
		{
			cout<<"ENQUEUING..."<<endl;
			if(isFull())
			{
				cout<<"ERROR"<<endl;
				return;
			}
			if(isEmpty())
			{
				front=rear=0;
			}
			
			else
			{
				rear=(rear+1)%MAX;
			}
			A[rear]=x;
			cout<<"Done Enqueuing"<<endl;
		}
		void Dequeue()
		{
			cout<<"DEQUEUING..."<<endl;
			if(isEmpty())
			{
				cout<<"ERROR"<<endl;
			}
			if(front==rear)
			{
				front=-1;rear=-1;
			}
			else
			{
				front=(front+1)%MAX;
			}
			cout<<"Done Dequeuing"<<endl;
		}
		int Front()
		{
			if(front==-1)
			{
				cout<<"ERROR"<<endl;
				return -1;
			}
			cout<<"FRONT:	"<<A[front]<<endl;
		}
		void printQueue()
		{
			int count = (rear+MAX-front)%MAX + 1;
			cout<<"Queue       : ";
			for(int i = 0; i <count; i++)
			{
				int index = (front+i) % MAX;
				cout<<A[index]<<" ";
			}
			cout<<"\n\n";	
		}
};

int main()
{
	Queue Q;
	Q.Front();
	Q.Enqueue(2);Q.printQueue();
	Q.Enqueue(4);Q.printQueue();
	Q.Enqueue(5);Q.printQueue();
	Q.Enqueue(6);Q.printQueue();
	Q.Enqueue(7);Q.printQueue();
	Q.Enqueue(9);Q.printQueue();
	Q.Dequeue();Q.printQueue();
	Q.Dequeue();Q.printQueue();
	Q.Dequeue();Q.printQueue();
	Q.Front();
}
