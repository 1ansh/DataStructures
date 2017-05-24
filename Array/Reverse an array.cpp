#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

void reverseArray(int arr[],int start,int end)
{
	int temp;
	while(start<end)
	{
		temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		start++;
		end--;
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
	int start,end;
	start=0;
	end=n-1;
	reverseArray(arr,start,end);
	cout<<"Reversed array:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}	
}

