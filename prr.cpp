#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a;
	int arr[]={1,2,3,4,5};
	cin>>a;
	int *q=find(arr,arr+4,a);
	cout<<*q;
	return 0;
	
}
