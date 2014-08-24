#include<bits/stdc++.h>
using namespace std;
bool myfunction(char *str1,char *str2)
{
	return lexicographical_compare(str1,str1+12,str2,str2+12);
}
int main()
{
	int T;
	vector<char *> arr;
	cin>>T;
	int i=0;
	while(i<T)
	{
		char *str = new char(12);
		cin>>str;
		arr.push_back(str); 
		i++;
	}
	sort(arr.begin(),arr.end(),myfunction);
	/*for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<endl;
	}*/
	int Query;
	cin>>Query;
	while(Query--)
	{
		char str[12];
		cin>>str;
		int score = 0;
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]<=90)
			score += str[i]-64;
			else
			score += str[i]-96;
		}
		//cout<<score<<endl;
		for(int i=0;i<arr.size();i++)
		{
			if(*arr[i]==*str)
			{
				//cout<<"Found";
				score = score*(i+1);
				cout<<score<<endl;
				break;
			}
		}
	}
}

