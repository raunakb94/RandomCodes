#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int count;
	cin>>count;
	while(count >0)
	{
		
		int low=0;
		int high=100000000;
		int r;
		int res =0;
		cin>>r;
		while(r>0)
		{
			int ll=0;
		int hh=100000000;
			char a,b[3];
			int p;
			cin>>a>>p>>b;
			if((a=='<') && (b[0]=='y'))
			{
				hh=p;	
			}	
			else if((a=='>')&& (b[0]=='n'))
			{
				hh=p;
			}
			else if((a=='<') && (b[0]=='n'))
			{
				ll=p;
			}	
			else if((a=='>') && (b[0]=='y'))
			{
				ll=p;
			}
			if((ll>low) && (hh<high))
			{	
				ll=low;
				hh==high;
			}
			if((ll>high) || (hh<low))
			{
				res ++;
			}
			r--;
		}
		cout<<res;
		count--;
	}
}
