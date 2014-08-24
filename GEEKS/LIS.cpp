#include <iostream>
#include <vector>
#include <algorithm>
//Dynamic Programming O(n2) Approach
using namespace std;
int main()
{
	int n;
	vector<int> arr;
	cin>>n;
	int lis[n];
	int p = n;
	while(p>0)
	{
		int data;
		cin>>data;
		arr.push_back(data);
		p--;
	}
	for(int i = 0;i<n;i++)
	{
		lis[i]=1;
	}
	int max = 0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if((arr[i]>arr[j])&&(lis[i]<lis[j]+1))
			lis[i]=lis[j]+1;
			if(lis[i]>max)
			{
				max = lis[i];
			}
		}
	}
	cout<<endl<<max;
	return 0;
}
