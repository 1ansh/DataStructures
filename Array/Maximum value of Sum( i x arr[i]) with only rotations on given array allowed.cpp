#include <bits/stdc++.h>
 
using namespace std;

int maxSum(int arr[],int n)
{
	int i,j,arrsum=0;
	int currsum=0;
	for(i=0;i<n;i++)
	{
		arrsum = arrsum+arr[i];
		currsum = currsum + i*arr[i];
	}
	int maxval = currsum;
	for(j=1;j<n;j++)
	{
		currsum = currsum +arrsum - n*arr[n-j];
		if(currsum > maxval)
		{
			maxval = currsum;
		}
	}
	return maxval;
}

int main(void)
{
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\nMax sum is " << maxSum(arr, n);
    return 0;
}
