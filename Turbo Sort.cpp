//Turbo Sort
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long getn()
{long long  i=0;
 char ch=getchar_unlocked();
 while(ch>'9'||ch<'0')
 ch=getchar_unlocked();
 while(ch<='9'&&ch>='0')
 {i=(i<<1)+(i<<3)+ch-'0';
  ch=getchar_unlocked();
 }
return i;
}


int main()
{
	int n;
	cin>>n;
	vector<long long> arr(n);
	for(long long i = 0;i<n;i++)
	{
		long long temp = getn();
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end());
	for(long long i = 0;i<n;i++)
	{
		printf("%lld\n",arr[i]);
	}
	return 0;
}
