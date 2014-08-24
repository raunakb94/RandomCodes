#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int c;
	cin>>c;
	while(c)
	{
		vector<int> arr;
		//vector<int> arr2;
		for(int i=0;i<c;i++)
		{
			int p;
			cin>>p;
			arr.push_back(p);
		}
		sort(arr.begin(),arr.end());
		int res = 0;			// 2 7 9 10 11

		for(int i=0;i<c-1;i++)
		{
			
		}
		cout<<res<<endl;
		cin>>c;
	}
}
