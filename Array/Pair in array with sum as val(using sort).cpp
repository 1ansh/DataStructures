#include <iostream>
using namespace std;

bool hasArrayTwoCandidates(int arr[],int n,int val)
{
	int l,r;
	l=0;r=n-1;
	while(l<r)
	{
		if(arr[l]+arr[r]==val)
		{
			return true;
		}
		else if(arr[l]+arr[r]>val)
		{
			r--;
		}
		else if(arr[l]+arr[r]<val)
		{
			l++;
		}
	}
	return false;
}


void merge(int arr[],int l,int m,int r)
{
	int i,j,k,n1,n2;
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		L[i]=arr[l+i];
	}
	for(j=0;j<n2;j++)
	{
		R[j]=arr[m+1+j];
	}
	i=0;
	j=0;
	k=l;
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
}

void mergeSort(int arr[], int l,int r)
{
	int m;
	if(l<r)
	{
		m=l+(r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

int main()
{
	cout<<"Size of array: "<<endl;
	int n;
	cin>>n;
	int arr[n],i,val;
	cout<<"Array: "<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Value: "<<endl;
	cin>>val;
	mergeSort(arr,0,n-1);
	if( hasArrayTwoCandidates(arr,n,val))
        cout<<"Array has two elements with sum "<<val<<endl;
    else
        cout<<"Array doesn't have two elements with sum "<<val<<endl;
}
