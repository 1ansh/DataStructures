#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

bool isValid(string s)
{
    int i=0,flag=0;
    stack<char> s1;
    while(s[i]!='\0')
    {
        if(s[i]=='(' )
            s1.push(')');
        else if(s[i]=='{' )
            s1.push('}');
        else if(s[i]=='[' )
            s1.push(']');
        else if(s1.empty() || s1.top()!=s[i])
        {
            return false;
        }
        else
        s1.pop();
        i++;
    }
   return s1.empty();
}

int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		string s,stack;
		cin>>s;
		int k=isValid(s);
		if(k==1)
		{
			cout<<"BALANCED"<<endl;
		}
		else
		{
			cout<<"NOT BALANCED"<<endl;
		}
	}
}
