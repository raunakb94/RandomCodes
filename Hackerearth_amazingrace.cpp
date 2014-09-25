#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	//vector<int>arr;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int>arr;
		while(n--)
		{
			int n;
			cin>>n;
			arr.push_back(n);
		}
		int arrL[arr.size()],arrR[arr.size()];
	n = arr.size();
	arrR[n-1] = n-1;
	arrL[0]=0;
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]<arr[i+1])
		{
			arrR[i]=i+1;
			//cout<<"L1"<<endl;
		}
		else if(arr[i]==arr[i+1])
		{
			arrR[i]=arrR[i+1];
		}
		else
		{
			int j =i+1;
			while(arr[i]>=arr[j] && j<n)
			{
				j = arrR[j];
				if(j==n-1)
				break;
			//	cout<<"L2"<<endl;
			}
			arrR[i]=j;
		}
	}
	for(int i=1;i<arr.size();i++)
	{
		if(arr[i]<arr[i-1])
		{
			arrL[i]=i-1;
			//cout<<"L3"<<endl;
		}
		else if(arr[i]==arr[i-1])
		{
			arrL[i]=arrL[i-1];
		}
		
		else{
			int j = i-1;
			while(arr[i]>=arr[j] && j>=0)
			{
				j = arrL[j];
				if(j==0)
				break;
			//	cout<<"L4"<<endl;
			}
			arrL[i]=j;
		}
	}
	int max = 0;
	int mInd = 0;
	for(int i=0;i<n;i++)
	{
		int x = (i-arrL[i])+(arrR[i]-i);
		int p = i +1;
		int res = (x*p)%1000000007;
		if(res>max)
		{
			max = res;
			mInd = i+1;
		}
	}
	cout<<mInd<<endl;
	}
	
}

