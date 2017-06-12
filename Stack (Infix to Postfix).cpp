#include <bits/stdc++.h>      
using namespace std;


#define MAX 1000

class Stack
{
	int top;	
	public:
		char a[MAX];
		Stack(){top=-1;}
		char attop()
		{
			return  a[top];
		}
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

int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}


void infixToPostfix(string exp)
{
	Stack s;
	string post;
	int i,ind=0;
	for(i=0;i<exp.size();i++)
	{
		if((exp[i]>='a' && exp[i]<='z') ||(exp[i]>='A' && exp[i]<='Z'))
		{
			post+=exp[i];
		}
		else if(exp[i]=='(')
		{
			s.push(exp[i]);
		}
		else if(exp[i]==')')
		{
			while(s.attop()!='(' && !(s.isEmpty()))
			{
				post+=s.pop();
			}
			s.pop();
		}
		else
		{
			while(!(s.isEmpty()) && prec(s.attop())>=prec(exp[i]))
			{
				if(s.attop()=='(')
				{
					s.pop();
				}
				post+=s.pop();
			}
			s.push(exp[i]);
		}
		
	}
	while(!(s.isEmpty()))
		{
			if(s.attop()=='(')
			{
				s.pop();
			}
			post+=s.pop();
		}
	cout<<post<<endl;
}


int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
