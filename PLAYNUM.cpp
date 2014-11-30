#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<long long> arr,arra,arrb;
	int num_test;
	long long count ;
	cin>>num_test;
	while(num_test>0)
	{
		count=0;
		long long n,q;
		cin>>n>>q;
		while(n>0)
		{
			long long key;
			cin>>key;
			arr.push_back(key);
		n--;
		}
		vector<long long> a=arr;
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		
		long long q2=q;
		while(q2>0)
		{long long p=0;
			long long a,b;
			cin>>a>>b;
			arra.push_back(a);
			arrb.push_back(b);
		}
		long long min=min_element(arra.begin(), arra.end());;
		long long max=max_element(arrb.begin(), arrb.end());;
		while(q>0)
		{
			
		}
		cout<<count<<endl;
		num_test--;
		arr.clear();
	}
	return 0;
}
