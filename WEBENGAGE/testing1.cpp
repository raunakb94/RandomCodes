#include<bits/stdc++.h>
using namespace std;
vector<int>[] mazeToGraph(int arr[][])
{
	
}
int main()
{
	int n;
	cout<<"Enter The Size oF The Matrix";
	cin>>n;
	int arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int d;
			cin>>d;
			arr[i][j]=d;
		}
	}
	mazeToGraph(arr);
}

