#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	long long q;
	cin>>n;
	while(n>0)
	{
		int p;
		cin>>p;
		vector<long long> arr(p);
		long long max = 0;
		for(int i=0;i<p;i++)
		{
			long long s;
			cin>>s;
			arr.push_back(s);
			if(s>max)
			max = s;
		}
		q = max;
		cout<<"MAX"<<q<<max<<endl;
		for(int i=0;i<p-1;i++)
		{
			int r = 0;
			while((max-1)-arr[i+1]<0)
			{
				q++;
				max++;
				r = 1;
				cout<<"INCREasing";
			}
			cout<<"MAX-- "<<max<<"   ";
			if(r==1)
			{
			max = q - i;
			r =0;
			cout<<"Decreasing";
			}
			max--;
			cout<<"LOOP";
		}
		cout<<q<<endl;
		n--;
	}
}
