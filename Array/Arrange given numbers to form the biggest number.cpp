#include <bits/stdc++.h>
using namespace std;

bool myfunc(string X,string Y)
{
	string XY = X.append(Y);
	string YX = Y.append(X);
	
	return XY.compare(YX)>0 ? 1 :0;
}

void printLargest(vector<string> arr)
{
	sort(arr.begin(),arr.end(),myfunc);
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i];
	}
	cout<<endl;
}
 
int main()
{
    vector<string> arr;
 
    //output should be 6054854654
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    printLargest(arr);
 
    // output should be 777776
    /*arr.push_back("7");
    arr.push_back("776");
    arr.push_back("7");
    arr.push_back("7");*/
 
    //output should be 998764543431
    /*arr.push_back("1");
    arr.push_back("34");
    arr.push_back("3");
    arr.push_back("98");
    arr.push_back("9");
    arr.push_back("76");
    arr.push_back("45");
    arr.push_back("4");
    */
 
   return 0;
}
