#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

void printLeaders(int arr[],int n)
{
	int max,i;
	max=arr[n-1];
	cout<<max<<" ";
	for(i=n-2;i>=0;i--)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			cout<<max<<" ";
		}
	}
}

int main()
{
	int n,i;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter array elements:"<<endl;
	int arr[n],val,index;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"LEADERS:"<<endl;
	printLeaders(arr,n);	
}

