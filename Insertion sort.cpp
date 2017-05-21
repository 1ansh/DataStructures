#include <iostream>


using namespace std;

void insertionSort(int arr[],int n)
{
	int i,j,key;
	for(j=1;j<n;j++)
	{
		key=arr[j];
		i=j-1;
		while(i>=0 and arr[i]>key)
		{
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=key;
	}
}

int main()
{
    int n,i,j,key;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter array elements:"<<endl;
    for(i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
	insertionSort(arr,n);
	cout<<"Sorted array:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
