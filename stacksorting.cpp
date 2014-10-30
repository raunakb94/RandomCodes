/*
	Author : Raunak Bhansali
	Stack Sorting Using only One Extra Stack(Assumption All Elements >0)
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int>st1,st2;
	int T;
	cin>>T;
	while(T--)
	{
		int data;
		cin>>data;
		while(data<=0)
			{
				cout<<"Enter Correct Data"<<endl;
				cin>>data;
			}
		st1.push(data);
	}
	while(!st1.empty())
	{
		//cout<<"Hello";
		if(st2.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
		else
		{
			int key = st1.top();
			st1.pop();
			st1.push(0);
			while(!st2.empty() && key<st2.top())
			{
				st1.push(st2.top());
				st2.pop();
			}
			st2.push(key);
			while(st1.top()!=0)
			{
				st2.push(st1.top());
				st1.pop();
			}
			st1.pop();
		}
	}
	cout<<"Sorted Array Is"<<endl;
	while(!st2.empty())
	{
		cout<<st2.top()<<endl;
		st2.pop();
	}
}

