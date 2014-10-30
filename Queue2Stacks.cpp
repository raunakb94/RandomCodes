/*
	Author : Raunak Bhansali
	Queue using two Stacks
*/
#include<bits/stdc++.h>
using namespace std;
class Queue{
	stack<int>st1,st2;
	static int count;
	public:
		Queue()
		{
			//count++;
		}
		int push_back(int data)
		{
			st1.push(data);
			return 1;
		}
		int pop_front()
		{
			if(st1.empty()&&st2.empty())
			{
				return -1;
			}
			if(st2.empty())
			{
				while(!st1.empty())
				{
					st2.push(st1.top());
					st1.pop();
				}
			}
			int q = st2.top();
				st2.pop();
				return q;
			
		}
};
int main()
{
	Queue Q1;
	int ch = 1;
	while(ch!=0)
	{
		if(ch==1)
		{
			cout<<"Enter an Element in Queue"<<endl;
			int data;
			cin>>data;
			while(data<=0)
			{
				cout<<"Enter Correct Data"<<endl;
				cin>>data;
			}
			Q1.push_back(data);
		}
		else if(ch==2)
		{
			int popped = Q1.pop_front();
			if(popped>=0)
			cout<<"Popping"<<popped<<endl;
			else cout<<"Queue is Empty";
		}
		cout<<"Enter 1 or 2";
		cin>>ch;
	}
}

