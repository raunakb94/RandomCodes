#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	int cost =0;
	int i=0;
	if(n*a>(n/m)*b)
	{
		cost+=(n/m)*b;
		n-=(n/m)*m;
	}
	else 
	{
		cost+=n*a;
		n=0;
	}
	//cout<<n<<endl;
	if(n*a<b)
	{
		cost+=n*a;
	}
	else cost+=b;
	cout<<cost<<endl;
}

