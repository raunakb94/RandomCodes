/*
	Author Raunak Bhansali
	
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("input.txt", "r", stdin);
	int r,c;
	cin>>r>>c;
	int arr[r][c];
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			int data;
			cin>>data;
			arr[i][j]=data;
		}
	}
	//cout<<"Success Input";
	int dp[r][c];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<r;i++)
	{
		dp[i][0] = arr[i][0];
	}
	for(int j=0;j<c;j++)
	{
		dp[0][j]=arr[0][j];
	}
	for(int i=1;i<r;i++)
	{
		for(int j=1;j<c;j++)
		{
			if(arr[i][j]==1)
			{
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			}
			else
			dp[i][j]=0;
		}
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<dp[i][j];
		}
		cout<<endl;
	}
}

