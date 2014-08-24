#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int c;
	vector<int> arr(100,0);
	string str;
	cin>>c;
	while(c>0)
	{
		int p;
		cin>>p;
		cin>>str;
		++arr[p];
		c--;
	}
	for(int i=0;i<100;i++)
	{
		arr[i+1]+=arr[i];
		cout<<arr[i]<<" ";
	}
}
