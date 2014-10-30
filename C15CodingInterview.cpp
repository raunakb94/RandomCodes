/*
Author : Raunak Bhansali
Programm to successfully implement Extract Min operation in a stack in O(1) time Complexity
*/

#include<bits/stdc++.h>
using namespace std;
class MinStack{
	stack<int> stk;
	stack<int> stkMin;
	static int count;
	public:
		bool push(int data)
		{
			bool val = false;
			if(stkMin.empty() || data<stkMin.top())
			{
				stkMin.push(data);
			}
			else
			stkMin.push(stkMin.top());
			
			stk.push(data);
			val = true;
			return val;
		}
		int pop()
		{
			if(stk.empty())
			return -1;
			
			int d = stk.top();
			stkMin.pop();
			return d;
		}
		int peekMin()
		{
			if(stk.empty())
			{
				cout<<"Stack Empty"<<endl;
				return -1;
			}
			return stkMin.top();
		}
};
int main()
{
	int T = 1;MinStack st;
	while(T)
	{
		if(T==1)
		{
			cout<<"Enter A Element";
			int d;
			cin>>d;
			st.push(d);
			
		}
		if(T==2)
		{
			if(st.pop()>=0)
			cout<<"Element Popped";
		}
		if(T==3)
		{
			int q = st.peekMin();
			if(q>=0)
			cout<<"Min Of Stack = "<<q;
		}
		cout<<endl;
		cout<<"Enter 1 to add 2 to pop 3 to peek"<<endl;
		cin>>T;
	}
}

