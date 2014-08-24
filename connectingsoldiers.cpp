#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int max[a+1],min[a+1];
		max[0]=min[0]=0;
		max[1]=min[1]=2;
		for(int i=2;i<=a;i++)
		{
			
			max[i]=max[i-1]+i+1;
			min[i]=min[i/2]+min[i-(i/2)-1]+i+1;
		}
		//if(b>=min[a]&&b<=max[a])
		if(b>=min[a]&&b<=max[a])
		cout<<0;
		else if(b<min[a])
		cout<<-1;
		else
		cout<<b-max[a];
		
		cout<<endl;
	}
	
}
