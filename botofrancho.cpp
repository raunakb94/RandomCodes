#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<climits>
using namespace std;
	unsigned long long search(unsigned long long a,unsigned long long b);
vector< vector<unsigned long long> > mat;
void add(unsigned long long a,unsigned long long b)
{
	unsigned long long p=search(a,b);
	if(p==0)
	{
	vector<unsigned long long> temp;
	temp.push_back(a);
	temp.push_back(b);
	mat.push_back(temp);
	}
	return;
}
unsigned long long search(unsigned long long a,unsigned long long b)
{
	unsigned long long ret=0;
	for(unsigned long long i=0;i<mat.size();i++)
	{
		if(mat[i][0]==a && mat[i][1]==b)
		{
			ret=i;
			break;
		}
	}
	return ret;
}
void erase(unsigned long long a,unsigned long long b)
{
	unsigned long long p=search(a,b);
	vector<unsigned long long>::iterator ab;
	if(p!=0)
	{
		mat.erase(mat.begin()+p);
	}
}
void get(unsigned long long a,unsigned long long b)
{
	unsigned long long dist=ULLONG_MAX;
	unsigned long long p=0;
	unsigned long long q=0;
	for( unsigned long long i=0;i<mat.size();i++)
	{
		
		if(mat[i][0]>a && mat[i][1]>b)
		{
			 unsigned long long d =sqrt(((a-mat[i][0])*(a-mat[i][0]))+((b-mat[i][1])*(b-mat[i][1])));
			if(d<dist)
			{
				p=mat[i][0];
				q=mat[i][1];
				dist=d;
			}
		}
	}
	if(p!=0 && q!=0)
	cout<<p<<" "<<q<<endl;
	else
		cout<<-1<<endl;
		
}
int main()
{
	unsigned long long num_test;
	cin>>num_test;
	while(num_test>0)
	{
		unsigned long long a,b;
		string str;
		cin>>str;
		cin>>a>>b;
		if(str=="add")
		{
			add(a,b);
		}
		if(str=="get")
		{
			get(a,b);
		}
		if(str=="erase")
		{
			erase(a,b);
		}
		num_test--;
	}
	return 0;
}
