#include <iostream>
#include <cstring>
using namespace std;

int search(int arr[],int n,int k)
{
	int j,ind=-1;
	while(j<n)
	{
		if(arr[j]==k)
		{
			ind=j;
		}
		j++;
	}
	return ind;
}

int main()
{
	int n;
	cout<<"Enter the initial size of array:";
	cin>>n;
	int arr[n],i,j=0;
	cout<<"Enter array elements:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the item:";
	int k,ind;
	cin>>k;
	ind=search(arr,n,k);
	if(ind==-1)
	{
		cout<<"The element not found."<<endl;
	}
	else
	{
		cout<<k<<" is at index "<<ind<<endl;
	}
}

