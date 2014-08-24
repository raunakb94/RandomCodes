#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>

using namespace std;
int main()
{
	char data[256];
	gets(data);
	int down = floor(sqrt(strlen(data)));
	int up = ceil(sqrt(strlen(data)));
	cout<<down<<endl<<up;
	int minlen,minbreadth;
	int minar = 10000000;
	if(up==down)
	{
		minlen = up;
		minbreadth = up;
	}
	else
	{
		for(int i=up;i>=down;i--)
		{
			if(i*down<minar && i*down<=strlen(data))
			{
				minlen = i;
				minbreadth = down;
			}
		}
	}
	cout<<endl<<minlen<<endl<<minbreadth;
	return 0;
}
