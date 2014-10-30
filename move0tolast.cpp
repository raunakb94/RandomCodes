/*
  Author Raunak Bhansali
  Problem Statement :- Move all 0's to the end of an array
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	vector<int >arr;
	while(T--)
	{
		int data;
		cin>>data;
		arr.push_back(data);
	}
	int i=0,j=0;
	for( ;i<arr.size() && j<arr.size();)
	{
		if(arr[i]==0)
		{
			while(arr[j]==0 && j<arr.size())
			{
				j++;
			}
			int temp = arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
		}
		else
		{
			i++;j++;
		}
	}
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<endl;
	}
}

