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

void leftRotateM1(int a[],int d,int n) //time-O[n]   auxillary space-O[d]
{
	int i,temp[d];
	for(i=0;i<d;i++)
	{
		temp[i]=a[i];
	}
	for(i=d;i<n;i++)
	{
		a[i-d]=a[i];
	}
	for(i=n-d;i<n;i++)
	{
		a[i]=temp[i-n+d];
	}
}

void leftRotateM2(int a[],int d,int n) // time-O[n*d]	auxillary space-O[1]
{
	while(d>0)
	{
		int i,temp=a[0];
		for(i=1;i<n;i++)
		{
			a[i-1]=a[i];
		}
		a[n-1]=temp;
		d--;
	}
}


void printArray(int arr[], int size)
{
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
}
 
int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7};
   leftRotateM1(arr, 2, 7);
   leftRotateM2(arr, 2, 7);
   printArray(arr, 7);
   return 0;
}
