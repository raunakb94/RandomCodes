#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
	int sum = 0;
		cin>>N;
		for(int i=1;i<=N;i++)
		{
			sum+=(i*(N+1));
		}
		cout<<sum<<endl;
	}
}

