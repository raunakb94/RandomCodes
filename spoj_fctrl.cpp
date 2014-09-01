#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;	
	cin>>T;
	while(T--)
	{
		long long int N;
		cin>>N;
		long long int count =0;
		for(long long int i=5;i<=N;i=i*5)
		{
			count += N/i;
		}
		cout<<count<<endl;	
	}
}

