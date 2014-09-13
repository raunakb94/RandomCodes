#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int arr[T][T];
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<T;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<"Enter Index For Flood Fill";
	int x,y;
	cin>>x>>y;
	assert(x<T && y<T);
	Then Do DFS to assign every node with the value
}

