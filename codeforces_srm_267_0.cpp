#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int count =0;
	while(T--)
	{
		int p,q;
		cin>>p>>q;
		if((q-p)>=2)
		count++;
		
	}
	cout<<count;
}

