#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>arr;
	for(int i=0;i<m;i++)
	{
		int d;
		cin>>d;
		arr.push_back(d);
	}
	int ki;
	cin>>ki;
	int tot = 0;
	for(int i=0;i<arr.size();i++)
	{
		//cout<<"in"<<arr[i]<<endl;
		int p = 1;
		int c=0;//errors
		int test = 1;
		for(int j=0;j<32;j++)
		{
			if((p&ki)!=(p&arr[i]))
			{
				c++;
				//cout<<"Error"<<arr[i];
			}
			if(c>k)
			{
				test = 0;
				break;
			}
			
			p = p<<1;
		}
		if(test ==1)
		{
			tot++;
			//cout<<"->"<<arr[i]<<endl;
		}
		
	}
	cout<<tot;
}

