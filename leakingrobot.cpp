#include<bits/stdc++.h>
using namespace std;
void calc(int x,int y)
{
	int xx = 0;
	int yy = 0;
	int count = 0;
	int steps = 1;
	while((xx<=x)&&(yy<=y))
	{
		if(count%4==0)
		{
			int prev = xx;
			xx = xx+steps;
			if(y == yy)
			{
				if((x>=prev)&&(x<=xx))
				cout<<"Yes"<<endl;
				return;
			}
			steps++;
		}
		if(count%4 ==1)
		{
			int prev = yy;
			yy = yy +steps;
			if(x == xx)
			{
				if((y>=prev)&&(y<=yy))
				cout<<"Yes"<<endl;
				return;
			}
			steps++;
		}
		if(count%4 ==2)
		{
			int prev = xx;
			xx = xx-steps;
			if(y == yy)
			{
				if((x<=prev)&&(x>=xx))
				cout<<"Yes"<<endl;
				return;
			}
			steps++;
		}
		if(count%4 == 3)
		{
			int prev = yy;
			yy = yy-3;
			if(x == xx)
			{
				if((y<=prev)&&(y>=yy))
				cout<<"Yes"<<endl;
				return;
			}
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		calc(x,y);
	}
}
