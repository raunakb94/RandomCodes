/*program to find first repetition of any number if any between 1to N wit N+1 inputs*/
#include<iostream>
#include<conio.h>
#include<vector>
#include<assert.h>
#include<algorithm>
using namespace std;
int ret;
int multiple(vector<int> array,int a=0,int b=0)
	{
	cout<<a<<b<<endl;
	int v;
	if(b-a==2)
	{
		
			if(array[a]==array[a+1])
			ret = a;
			else
			ret=a+1;
		
		return ret;
	}
	if(array[(b-a)/2]!=a+1+(b-a)/2)
	v=multiple(array,0,(b-a)/2);
	else
	v=multiple(array,((b-a)/2)+1,b);
	return v;	
	}
int main()
{
	vector<int> arr;
	vector<int>::iterator it;
	cout<<"Enter any Number :: ";
	int choice;
	cin>>choice;
	int ch=0;
	while(ch<=choice)
	{
		it=arr.end();
		int a;
		cout<<"Enter The NUmber";
		cin>>a;
		if(!(a>0 && a<=choice))
		exit(0);
		arr.insert(it,a);
		++ch;
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<endl;
	}
	cout<<"Repetition is at index"<<multiple(arr,0,arr.size()-1);
return 0;	
}

