#include<iostream>
using namespace std;
int main()
{
	int coins[]={1,2,5};
	int min[10];
	min[0]=0;
	for(int i=1;i<10;i++)
	{
		min[i]==99999;
	}
	
	for(int i=1;i<10;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(coins[j]<=i && min[i-coins[j]]<min[i])
				min[i]=min[i-coins[j]]+1;
		}
	}
	for(int i=0;i<10;i++)
	{
		cout<<min[i]<<endl;
	}
	return 0;
}
