/*
  Author Raunak Bhansali
  Problem Statement
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	long long int S,E;
	while(T--)
	{
		
		cin>>S>>E;
	
	long long int N;
	cin>>N;
	int x = 0;
	while(N--)
	{
			long long int a,b;
			cin>>a>>b;
			if((b<=E && a>=S) || (a<=S && b>S) || (a<E && b>=E))
			{
				x=1;
			}
	}
	if(x == 0)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	}
}


