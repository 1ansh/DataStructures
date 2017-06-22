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

void merge(int L[],int R[],int n1,int n2)
{
	int i,j,k;
	int arr[n1+n2];
	i=0;
	j=0;
	k=0;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
	if((n1+n2)%2==0)
	{
		cout<<(arr[(n1+n2)/2]+arr[(n1+n2)/2-1])/2;
	}
	else
	{
		cout<<arr[(n1+n2-1)/2];
	}
}


int main()
{
    int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10, 11};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    merge(ar1, ar2, n1, n2);
    return 0;
}
