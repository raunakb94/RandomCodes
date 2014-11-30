#include<iostream>
using namespace std;
int main()
{
	int num_test;
	cin>>num_test;
	int count=0;
	while(num_test>0)
	{
		int arr[3][2];
		cin>>arr[0][0]>>arr[0][1]>>arr[1][0]>>arr[1][1]>>arr[2][0]>>arr[2][1];		
		int x=(arr[1][0]-arr[0][0])*(arr[1][0]-arr[0][0])+(arr[1][1]-arr[0][1])*(arr[1][1]-arr[0][1]);
		int y=(arr[2][0]-arr[1][0])*(arr[2][0]-arr[1][0])+(arr[2][1]-arr[1][1])*(arr[2][1]-arr[1][1]);
		int z=(arr[2][0]-arr[0][0])*(arr[2][0]-arr[0][0])+(arr[2][1]-arr[0][1])*(arr[2][1]-arr[0][1]);
		if(x==(y+z)||y==(x+z)||z==(x+y))
		count ++;
		num_test--;
	}
	cout<<count;
	return 0;
}
