#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> arr;
		map<int,int>m1;
		while(n--)
		{
			int c;
			cin>>c;
			if(m1[c])
			{
				m1[c]++;
			}
			else
			arr.push_back(c);
			
		}
		sort(arr.begin(),arr.end());
		int s = 0;
		for(int i=0;i<arr.size();i++)
		{
			int p = m1[arr[i]];
			s+=((p*p)+p)/2;
		}
		cout<<s<<endl;
	}
}

