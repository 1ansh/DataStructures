#include <iostream>
#include <cstring>
using namespace std;

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
	while(j<n)
	{
		if(arr[j]==k)
		{
			ind=j;
		}
		j++;
	}
	cout<<k<<" is at index "<<ind<<endl;
}

