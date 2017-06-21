// MOORE'S VOTING ALGORITHM

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int findCandidate(int arr[],int n)
{
	int maj_ind=0;
	int count=1;
	int i;
	for(i=1;i<n;i++)
	{
		if(arr[maj_ind]==arr[i])
		{
			count++;
		}
		else
		{
			count--;
		}
		if(count==0)
		{
			maj_ind=i;
			count=1;
		}
	}
	return arr[maj_ind];
}

bool isMajority(int arr[],int n,int element)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==element)
		{
			count++;
		}
		if(count>n/2)
		{
			return true;
		}
	}
	return false;
}

void printMajority(int arr[],int n)
{
	int cand;
	cand=findCandidate(arr,n);
	if(isMajority(arr,n,cand))
	{
		cout<<"Majority Element = "<<cand;
	}
	else
	{
		cout<<"No Majority Element.";
	}
}

 
int main()
{
    int a[] = {1, 3, 3, 1, 3};
    int size = (sizeof(a))/sizeof(a[0]);
    printMajority(a, size);
    getchar();
    return 0;
}
