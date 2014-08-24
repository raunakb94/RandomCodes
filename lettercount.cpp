#include<iostream>
#include<map>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream myfile("example.txt");
//	cout<<"Enter a name";
	string arr;
//	getline(cin,arr);
	map<char,int> mymap;
	map<char,int>::iterator it;
	if(myfile.is_open())
	{
		while(getline(myfile,arr))
		{
				for(int i = 0;i<arr.size();i++)
				{
					mymap[arr[i]]++;
				}
		}
	}
	cout<<endl<<"Output"<<endl;
	it = mymap.begin();
	while(it!=mymap.end())
	{
		cout<<it->first<<"   <<Count total>>   "<<it->second<<endl;
		it++;
	}
	cout<<endl<<"Program Compl";
	getch();
	return 0;
}
