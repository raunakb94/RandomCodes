#include<bits/stdc++.h>
using namespace std;
map<int,int>m1;
int dfs(vector<int>arr[],int i,int test[],int count)
{
	if(!m1[arr[i][0]] && test[arr[i][0]]==0 && arr[i][0]!=i)
	{
		//Node not found
		test[arr[i][0]]=1;
		cout<<"Going to"<<arr[i][0]<<endl;
		int q = dfs(arr,arr[i][0],test,count+1);
		
		m1[i]=q+1;
		return 1+q;
	}
	else if(arr[i][0]==i)
	{//Leaf Node
		m1[i]=1;
		return 1;
	}
	else if(m1[arr[i][0]])
	{
		//if already found
		m1[i]=1+m1[arr[i][0]];
		return m1[i];
	}
	else
	{
		m1[i]=
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int>arr[n];
		int test[n];
		memset(test,0,sizeof(test));
		int p = n;
		int i=0;
		while(i<n)
		{
			int c;
			cin>>c;
			arr[i++].push_back(c);
		}
		for(int i=0;i<p;i++)
		{
			if(!m1[i])
			{
				if(arr[i][0]==i)
				{
					m1[i]=0;
				}
				else
				{
					cout<<"Sending "<<i<<endl;
				test[i]=1;
				int res = dfs(arr,i,test+1);
				m1[i]=res;
				}
				
			}
		}
		int min = 0;
		int minI = 0;
		for(int i=0;i<n;i++)
		{
			cout<<"mi"<<m1[i]<<endl;
			if(m1[i]>min)
			{
				min = m1[i];
				minI = i;
			}
		
		}
		cout<<minI<<endl;
	}
}

