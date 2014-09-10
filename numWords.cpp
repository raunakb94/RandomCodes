#include<bits/stdc++.h>
using namespace std;
char arr[][10] = {"this","is","a","an","the","good","boy","girl","name"};
int findString(vector<string>dict,string key)
{
	for(int i=0;i<dict.size();i++)
	{
		if(dict[i]==key)
		return 1;
	}
	 return 0;
}
string getstring(string str,int i,int j)
{
	string str2[j-i+1];
	int q=0;
	for(int p=i;p<=j;p++,q++)
	{
		str2[q]=str[i];
	}
	return str2;
}
int getNumWords(string str)
{
	
}
int main()
{
	
	vector<string> dict;
	for(int i=0;i<9;i++)
	{
		dict.push_back(arr[i]);
	}
	cout<<"Enter The Sentence to search For";
	string str;
	getline(cin,str);
	cout<<"NUm of Words"<<getNumWords(str);
}

