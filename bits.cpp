#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
//#define bit 4294967296
using namespace std;
int main()
{
	long long int num_test;
	cin>>num_test;
	while(num_test>0)
	{
	
	long long int a,b;
	cin>>a>>b;
	int count=0;
	for(long long i=a;i<=b;i++)
	{
		long long int copy=i;
		if(i<0)
		{
		copy = 4294967296-((-1)*copy);
		bitset<32> y(copy);
		//cout<<copy<<endl<<y<<endl;
		for(int c=0;c<32;c++)
		{
			if(y[c]==1)			
			count++;
		}
		}
		
		else
		{
		bitset<32> y(copy);
		for(int c=0;c<32;c++)
		{
			if(y[c]==1)
			count++;
		}
		}
		
	}
	
	cout<<count<<endl;
	num_test--;
}
	return 0;
	
	
}
