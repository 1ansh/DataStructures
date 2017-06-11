#include <bits/stdc++.h>      
using namespace std;


#define MAX 1000

class Stack
{
	int top;	
	public:
		int a[MAX];
		Stack(){top=-1;}
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


int evaluatePostfix(char* exp)
{
	Stack s;
	int i,op1,op2,res;
	for(i=0;exp[i];i++)
	{
		if(exp[i]=='*')
		{
			op1=s.pop();
			op2=s.pop();
			res=op2*op1;
			s.push(res);
		}
		else if(exp[i]=='+')
		{
			op1=s.pop();
			op2=s.pop();
			res=op2+op1;
			s.push(res);
		}
		else if(exp[i]=='-')
		{
			op1=s.pop();
			op2=s.pop();
			res=op2-op1;
			s.push(res);
		}
		else
		{
			res=int(exp[i])-48;
			s.push(res);
		}
	}
	return s.pop();
}

int evaluatePrefix(char* exp)
{
	Stack s;
	int i,op1,op2,res;
	for(i=strlen(exp)-1;i>=0;i--)
	{
		if(exp[i]=='*')
		{
			op1=s.pop();
			op2=s.pop();
			res=op2*op1;
			s.push(res);
		}
		else if(exp[i]=='+')
		{
			op1=s.pop();
			op2=s.pop();
			res=op2+op1;
			s.push(res);
		}
		else if(exp[i]=='-')
		{
			op1=s.pop();
			op2=s.pop();
			res=op2-op1;
			s.push(res);
		}
		else
		{
			res=int(exp[i])-48;
			s.push(res);
		}
	}
	return s.pop();
}

int main()
{
//    char exp[] = "231*+9-";    POSTFIX
    char exp[] = "-9+*132";		//PREFIX
//    printf ("Value of %s is %d", exp, evaluatePrefix(exp));
    printf ("Value of %s is %d", exp, evaluatePrefix(exp));
    return 0;
}
