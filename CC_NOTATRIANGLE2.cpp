#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int c;
	cin>>c;
	while(c)
	{
		vector<int> arr(c);
		vector<int> arr2;
		for(int i=0;i<c;i++)
		{
			int p;
			cin>>p;
			arr.push_back(p);
		}
		sort(arr.begin(),arr.end());
		int ans = 0;
	for(int i = 0; i < c-2; i++)
		{
			//cout<<"HI1";
			int I = 0;
			int r = c-i-2;
			while(I < r)
			{
			//	cout<<"HI2";
				if(arr[I] + arr[r] < arr[c-i-1])
				{
					ans += r - I;
					I++;
				}
				else r--;				
			}
		}
 
		cout << ans << endl;
	cin>>c;	
	}
 
	return 0;
} 
