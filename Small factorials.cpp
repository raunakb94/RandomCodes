//Small factorials
#include<iostream>
using namespace std;
int arr[200];
void multiply(int y)
{
//	cout<<"Mult";
	int temp = 0;
	int x = 0;
	for(int i=0;i<200;i++)
	{
		x = arr[i]*y+temp;
		arr[i]=x%10;
		temp = x/10;
	}
}
void fact(int n)
{//	cout<<"fact";
	arr[0]=1;
	for(int i=1;i<200;i++)
	{
		arr[i]=0;
	}
	int i=2;
	while(i<=n)
	{
		multiply(i);
		i++;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t>0)
	{//	cout<<"Enter";
		int n;
		cin>>n;
		fact(n);
	int i=199;
	int c = 0;
	while(i>=0)
	{
	if(arr[i]>0)
		{
			c =1;
		}
		if(c == 1)
		{
			cout<<arr[i];
		}--i;
	}
	--t;
	}
	return 0;
}
