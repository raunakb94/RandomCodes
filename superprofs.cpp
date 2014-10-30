/*
  Author Raunak Bhansali
  Problem Statement
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	map<char,char>m1;
	while(T--)
	{
		char c1,c2;	
		cin>>c1>>c2;
		m1[c1]=c2;
		m1[c2]=c1;	
	}
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
	//	cout<<str[i];
		if(m1[str[i]])
		{
		//	cout<<"Yes";
			str[i]=m1[str[i]];
		}
	}
	cout<<str;
}

