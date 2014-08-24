#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int test;
	cin>>test;
	int temp = test;
	while(test>0)
	{
		int count;
		cin>>count;
		vector<int> data;
		while(count>0)
		{
			
			int d;
			cin>>d;
			data.push_back(d);
			count--;
		}
		
		sort(data.begin(),data.end());
		int t = 0;
		int high = data.size();
		int low = 0;
		while(low<high)
		{
			int mid = (low+high)/2;
			int data2 = data[mid] - (((mid+1)%6)+(mid+1)/6);
			if(data2>0)
			{
				low = mid+1;
			}
			else
			{
				cout<<"Goodbye Rick"<<endl;
				t = 1;
					break;
			}
		}
		if(t==0)
		cout<<"Rick now go and save Carl and Judas"<<endl;
		test--;
	}
	cout<<temp;
    return 0;
}

