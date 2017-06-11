#include <bits/stdc++.h>      
using namespace std;


#define MAX 1000

class Stack
{
	int top;	
	public:
		char a[MAX];
		Stack(){top=-1;}
		bool push(char x)
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
		char pop()
		{
			if(top<0)
			{
				cout<<"Stack Underflow"<<endl;
			}
			else
			{
				char x=a[top--];
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


void reverse(char* str)
{
	Stack s;
	int i;
	for(i=0;str[i];i++)
	{
		s.push(str[i]);
	}
	for(i=0;str[i];i++)
	{
		str[i]=s.pop();
	}
}


int main()
{
    char str[] = "GeeksQuiz";
 
    reverse(str);
    printf("Reversed string is %s", str);
 
    return 0;
}
