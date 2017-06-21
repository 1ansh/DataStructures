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

int getMissingNoMethod1(int arr[],int n)
{
	int i,total=(n+1)*(n+2)/2;
	for(i=0;i<n;i++)
	{
		total=total-arr[i];
	}
	return total;
}

int getMissingNoMethod2(int arr[],int n)
{
	int i,x1=arr[0],x2=1;
	for(i=1;i<n;i++)
	{
		x1=x1^arr[i];
	}
	for(i=2;i<=n+1;i++)
	{
		x2=x2^i;
	}
	return x1^x2;
}


int main()
{
    int a[] = {1,2,4,5,6};
    int miss1 = getMissingNoMethod1(a,5);
    int miss2 = getMissingNoMethod2(a,5);
    cout<<miss1<<endl<<miss2<<endl;
}
