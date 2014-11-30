#include<iostream>
#include<bitset>
using namespace std;
void expsquaring(int,int);
int main()
{
	cout<<"Enter in the form a^b";
	int a,b;
	cin>>a>>b;
	expsquaring(a,b);
	return 0;
}
void expsquaring(int a,int b)
{
	int x1=a;
	int x2=a*a;
	bitset bit(b);
	int size=bit.size();
	cout<<bit<<endl<<size<<endl;
	if(bit[size-1]==1)
	{
		cout<<bit<<endl;
		for(int i=size-2;i>=0;i--)
		{
			cout<<i<<endl;
			if(bit[i]==0)
			{
				x2=x1*x2;
				x1=x1*x1;
			}
			else
			{
				x1=x1*x2;
				x2=x2*x2;
			}
		}
	}
	cout<<x1;
	
}
