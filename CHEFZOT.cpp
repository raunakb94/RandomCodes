#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int c;
	cin>>c;
	int test = c;
	vector<int> arr;
	int i=0;
	int last=-1;
	int max = 0;
	while(c>0)
	{
		int p;
		cin>>p;
		if(p==0)
		{
			arr.push_back(i);
			if((i-last)>max)
			{	max = i-last;
			}
			last = i;
		}
		i++;
		c--;
	}
	if((test-last)>max)
	max=test-last;
	cout<<max-1;
}
