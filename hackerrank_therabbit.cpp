#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int p;
		cin>>p;
		//int step = 1;
		int arr[p+1];
		int arr2[p+1];
		
		memset(arr,0,sizeof(arr));
		memset(arr2,0,sizeof(arr2));
		arr[0]=1;
		arr2[0]=0;
		for(int i=0;i<=p;i++)
		{
			if((i+arr2[i]+1)<=p ||(i+arr2[i]+2)<=p)
			{
			if(arr[i]==1)
			{
				if(i+arr2[i]+1 <=p)
				{
					arr[i+arr2[i]+1]=1;
					arr2[i+arr2[i]+1]=arr2[i]+1;
				//	cout<<"1"<<endl;
				}
				if(i+arr2[i]+2<=p)
				{
					arr[i+arr2[i]+2]=1;
				arr2[i+arr2[i]+2]=arr2[i]+1;
			//	cout<<"2"<<endl;
				}
			}
			}
			else break;
			if(arr[p]==1)
			break;
		}
		cout<<arr2[p]<<endl;
	}
}

