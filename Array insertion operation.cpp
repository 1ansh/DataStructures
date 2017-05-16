#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the initial size of array:";
	cin>>n;
	int arr[n],i,j=n;
	cout<<"Enter array elements:"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	n=n+1;
	cout<<"Enter the index:";
	int k,val;
	cin>>k;
	cout<<"Enter the value:";
	cin>>val;
	while(j>=k)
	{
		arr[j+1]=arr[j];
		j=j-1;
	}
	arr[k]=val;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}

