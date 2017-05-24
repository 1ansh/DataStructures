#include <iostream>
#include <cstring>
using namespace std;

void deletion(int arr[],int n,int k)
{
	int j;
	j=k;
	while(j<(n-1))
	{
		arr[j]=arr[j+1];
		j=j+1;
	}
}

int main()
{
	int n;
	cout<<"Enter the initial size of array: ";
	cin>>n;
	int arr[n],i;
	cout<<"Enter array elements:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the index: ";
	int k;
	cin>>k;
	deletion(arr,n,k);
	cout<<"Array after deletion:"<<endl;
	n=n-1;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}

