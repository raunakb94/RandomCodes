#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>arr;
		while(N--)
		{
			int d;
			cin>>d;
			arr.push_back(d);
		}
		sort(arr.begin(),arr.end());
		int c =0 ;
		for(int i=0;i<arr.size();i++)
		{
			if(arr[i]>(i+(i/6)))
			{
				c++;
			}
			else break;
		}
		if(c==arr.size())
		cout<<"Rick now go and save Carl and Judas"<<endl;
		else cout<<"Goodbye Rick" <<endl<<c<<endl;
	}
}

