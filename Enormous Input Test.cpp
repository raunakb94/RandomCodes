//Enormous Input Test
 #include<iostream>
  #include<vector>
  #include<set>
  #include<map>
  #include<queue>
  #include<stack>
  #include<string>
  #include<algorithm>
  #include<functional>
  #include<iomanip>
  #include<cstdio>
  #include<cmath>
  #include<cstring>
  #include<cstdlib>
  #include<cassert>
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
	long long n,k;
	n=getn();
	k=getn();
	int count = 0;
	while(n>0)
	{
		long long c;
		c = getn();
		if(c%k==0)
		count ++;
		n--;
	}
	cout<<count;
	return 0;
}
