#include<iostream>
#include<conio.h>
using namespace std;
boolean union(int &arr2,int s,int d);
boolean find(int &arr2,int s,int d);
int root(int &arr,int p);
int main()
{
	cout<<"Enter the number of nodes";
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i =0;i<n;i++)
	{
		arr[i] = i;
	}
	
}
int root(int &arr,int p)
{
	int c = arr[p];
	while(c!=p)
	{
		c = arr[arr[p]];
		p = arr[p];
	}
	return c;
};

boolean union(int &arr2,int s,int d)
{
	if((arr2[s]==s) &&(arr2[d]==d))
	{
		if(s<d)
		arr2[d]=s;
		else
		arr2[s]=d;
		return true;
	}
	else 
	{
		int r1 = root(arr2,d);
		int r2 = root(arr2,s);
		if(r1<r2)
		arr2[r2]==r1;
		else
		arr2[r1]==r2;
		return true;
	}
	return false;
};
boolean find(int &arr2,int s,int d)
{
	if(arr2[s]==arr2[d])
	return true;
	else
	return false;
};
