#include <iostream>
#include <cstring>
using namespace std;

void update(int arr[],int k, int item)
{
	arr[k]=item;
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
	cout<<"Enter the index:";
	int k,item;
	cin>>k;
	cout<<"Enter the item:";
	cin>>item;
	update(arr,k,item);
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}

