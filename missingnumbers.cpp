#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	vector<int> arr1;
	cin>>a;
	int arra[100],arrb[100],arrc[100];
	memset(arra,0,sizeof(arra));
	memset(arrb,0,sizeof(arrb));
	memset(arrc,0,sizeof(arrc));
	while(a--)
	{
		int data;
		cin>>data;
		arra[data%100]++;
		arrc[data%100]=data;
		//cout<<"Inputa->>"<<data%100<<"->>"<<data<<endl;
	}
	cin>>a;
	vector<int> arr2;
	while(a--)
	{
		int data;
		cin>>data;
		arrb[data%100]++;
		arrc[data%100]=data;
		//cout<<"Inputb->>"<<data%100<<"->>"<<data<<endl;
	}
	vector<int>arrd;
	for(int i=0;i<100;i++)
	{	//cout<<"arra"<<arra[i]<<"arrb"<<arrb[i];
		if(arra[i]!=arrb[i])
		{
			arrd.push_back(arrc[i]);
			//cout<<"pushed"<<arrc[i]<<"i"<<i<<endl;
		}
	}
	sort(arrd.begin(),arrd.end());
	for(int i=0;i<arrd.size();i++)
	{
		cout<<arrd[i];
		if(i<arrd.size()-1)
		cout<<" ";
	}
	
}
