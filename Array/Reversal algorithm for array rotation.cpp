#include <bits/stdc++.h>
using namespace std; 

void reverse(int arr[],int l,int h)
{
	int temp;
	while(l<h)
	{
		temp = arr[l];
		arr[l] = arr[h];
		arr[h] = temp;
		l++;
		h--;
	}
}

void leftRotate(int arr[],int d,int n)
{
	reverse(arr,0,d-1);
	reverse(arr,d,n-1);
	reverse(arr,0,n-1);
}

void printArray(int arr[],int n)
{
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;
    leftRotate(arr, d, n);
    printArray(arr, n);
    return 0;
}
