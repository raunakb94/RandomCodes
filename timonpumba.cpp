#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
long myfunction (long x, long y) {return x^y;}
int main()
{
	int num_test;
	cin>>num_test;
	while(num_test>0)
	{
		vector<long> arr;
		int num;
		cin>>num;
		while(num>0)
		{
			int temp;
			cin>>temp;
			arr.push_back(temp);
			num--;
		}
		sort(arr.begin(),arr.end());
		long init=0;
		int p=accumulate(arr.begin(),arr.end(),init);
		for(long i=arr.size()-1;i>0;i--)
		{	int ret=0;
			long init=0;
			long xr=accumulate(arr.end()-i,arr.end(),init,myfunction);
			long left =accumulate(arr[0],arr[i-1],init);
			for(int j=i-1;j>=0;j--)
			{
				long init = 0;
				if((myfunction(xr,arr[j])==left-arr[j])&& (accumulate(arr.end()-i,arr.end(),init)+arr[j])>p/2)
				{
					cout<<accumulate(arr.end()-i,arr.end(),init)+arr[j]<<endl;
					ret =1;
				}
				
			}
			if(ret==0)
			cout<<"NO"<<endl;
		}
		num_test--;
	}
}
