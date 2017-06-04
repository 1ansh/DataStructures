#include<bits/stdc++.h>
using namespace std;
 
#define MAX 1000

class Stack
{
	int top;	
	public:
		int a[MAX];
		stack(){top=-1;}
		bool push(int x)
		{
			if(top>=MAX)
			{
				cout<<"Stack Overflow"<<endl;
				return false;
			}
			else
			{
				a[++top]=x;
				return true;
			}
		}
		int pop()
		{
			if(top<0)
			{
				cout<<"Stack Underflow"<<endl;
			}
			else
			{
				int x=a[top--];
				return x;
			}
		}
		bool isEmpty()
		{
			if(top<0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};


int main()
{
	struct Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
 
    cout << s.pop() << " Popped from stack\n";
 
    return 0;
}

