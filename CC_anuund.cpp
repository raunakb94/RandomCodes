#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
//#define long long int lli
int main()
{
	int c;
	cin>>c;
	while(c>0)
	{
		int n;	
		cin>>n;	
		vector<long long int> arr;
		while(n>0)
		{
			long long int p;
			//cout<<"Hello";
			cin>>p;
			arr.push_back(p);
			n--;
		}
		sort(arr.begin(),arr.end());
		for(int i=1;i<arr.size();i=i+2)
		{
		//	cout<<"Hello";
			long long int temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1] = temp;
		}
		for(int i=0;i<arr.size();i++)
		{
			cout<<arr[i];
		}
		c--;
	}
}
