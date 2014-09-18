#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>arr;
	while(n--)
	{
		int d;
		cin>>d;
		arr.push_back(d);
	}
	sort(arr.begin(),arr.end());
	int sum = 0;
	int pairs = 0;
	while(arr.size()>=2 && pairs<k)
	{
		//cout<<arr.size()<<endl;
		int test = 0;
		int i = arr.size()-1;
		int j=i;
		while(j>=0 && test==0)
		{
			if(arr[i]-arr[j]+1==m)
			{
				test = 1;
				sum+=(arr[i]);
				if(i!=j)
				sum+=arr[j];
				//cout<<arr[i]<<"->>"<<arr[j]<<endl;
				arr.erase(arr.begin()+i);
				if(i!=j)
				arr.erase(arr.begin()+j);
				pairs++;
			}
			j--;
		}
		if(test ==0)
		{
			arr.erase(arr.begin()+i);
		}
	}
	cout<<sum;
}

