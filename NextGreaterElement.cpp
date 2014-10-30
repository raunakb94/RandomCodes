/*
	Author : Raunak Bhansali
	Next GreaterElement In a Series Of Element Using Dynamic Programming
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		vector<int>arr;
		int count;
		cin>>count;
		int arr2[count];
		
		while(count--)
		{
			int data;
			cin>>data;
			arr.push_back(data);
		}
		arr2[arr.size()-1]=arr[arr.size()-1];
		//cout<<"Succ";
		for(int i = arr.size()-2;i>=0;i--)
		{
			if(arr[i]<arr[i+1])
			arr2[i]=arr[i+1];
			else
			if(arr[i]<arr2[i+1])
			arr2[i]=arr2[i+1];
			else
			arr2[i]= -1;
		}
		for(int i=0;i<arr.size();i++)
		{
			if(arr[i]==arr2[i])
			cout<<"-1"<<endl;
			else
			cout<<arr2[i]<<endl;
		}
	}
}

