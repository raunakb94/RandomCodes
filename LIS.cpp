#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	vector<int> arr;
	cin>>T;
	while(T>0)
	{
		int data;
		cin>>data;
		arr.push_back(data);
		T--;
	}
	cout<<"Inpur Done";
	int arr2[arr.size()];
	if(arr[0]>0)
	arr2[0]=arr[0];
	else arr2[0]=0;
	//int maxsum = 0;
	//int currsum = 0;
	for(int i=1;i<arr.size();i++)
	{
		int max = 0;
		for(int j=0;j<i;j++)
		{
			if(arr2[j]+arr[i]>max && arr[i]>arr[j])
			max = arr2[j]+arr[i];
		}
		if(max == 0)
		arr2[i]=arr2[i-1];
		else
		arr2[i]=max;
	}
	for(int i=0;i<arr.size();i++)
	cout<<arr2[i];
}
