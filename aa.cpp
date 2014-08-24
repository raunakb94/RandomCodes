#include<bis/stdc++.h>
using namespace std;
void schedule(int tables[],int order[],int arr[],int m,int n)
{
	memset(tables,-1,sizeof(tables));
	int i = 0;
	while(i<m)
	{
		int minvalue = 100000;
		int minindex = i;
		int j = 0;
		for(j=0;j<n;j++)
		{
			if(table[j]==order[i])
		break;
			if(arr[j]<minvalue)
			{
				minvalue = arr[j];
				mindex = j;
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
		int n,m;
		cin>>n;
		cin>>m;
		int order[m];
		int tables[n];
		int i = 0;
		while(i<m)
		{
			cin>>order[i];
			i++;
		}
		int arr[m];
		memset(arr,100000,sizeof(arr));
		for(int i=0;i<m;i++)
		{
			for(int j = i+1;j<m;j++)
			{
				if(order[i]==order[j])
				{
					arr[i]==j;
					break;
				}
			}
		}
		void schedule(tables,order,arr,m,n);
	}
}
