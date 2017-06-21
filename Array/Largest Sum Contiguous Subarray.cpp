// Kadane’s Algorithm
//O[n]

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

void maxSubArraySum(int a[],int n)
{
	int maxEnding=0,i,maxSoFar=0,start=0,end=0,s=0;
	for(i=0;i<n;i++)
	{
		maxEnding=maxEnding+a[i];
		if(maxEnding<0)
		{
			maxEnding=0;
			s=i+1;
		}
		if(maxEnding>maxSoFar)
		{
			maxSoFar=maxEnding;
			start=s;
			end=i;
		}
	}
	cout << "Maximum contiguous sum is " << maxSoFar<<endl;
	cout<<"Subarray with maximum sum: ";
	for(i=start;i<=end;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    maxSubArraySum(a, n);
    return 0;
}
