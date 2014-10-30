#include<bits/stdc++.h>
using namespace std;
int main()
{
	string S;
	getline(cin,S);
	stack<char>stk1;
	char str[4]="---";
	for(int i=0;i<S.length();i++)
	{
		if(S[i]!=' ')
		{
		//	string st = S[i];
			stk1.push(S[i]);
		}
		else
		{
			//stk1.push(str);
			for(int p=0;p<3;p++)
			{
				stk1.push(str[p]);
			}
			//stk1.push(S[i]);
		}
	}
	stack<char>stk2;
	while(!stk1.empty())
	{
		stk2.push(stk1.top());
		stk1.pop();
	}
	while(!stk2.empty())
	{
		cout<<stk2.top();
		stk2.pop();
	}
}

