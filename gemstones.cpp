#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int arr[t][26];
	memset(arr,0,sizeof(arr));
	int q=0;
	while(q<t)
	{
		string str;
		cin>>str;
		for(int i=0;i<str.length();i++)
		{
			arr[q][str[i]-97]++;
		}
	q++;
	}
	int count =0;
		//cout<<"dsa";
		for(int i=0;i<26;i++)
		{
			int j=0;
			for( j=0;j<t;j++)
			{
				if(arr[j][i]!=1)
				break;
			}
			if((j==t))
			count++;
		}
	cout<<count;
}
