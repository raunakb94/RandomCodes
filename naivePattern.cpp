#include<iostream>
#include<cstring>
using namespace std;
int naivePattern(char *txt,char *pat)
{
	int n = strlen(txt);
	int m = strlen(pat);
	cout<<n<<"dsada"<<m<<endl;
	int i=0;
	while(i<(n-m))
	{
		int j=0;
		while((txt[i+j]==pat[j])&&j<m)
		{
			cout<<"J"<<j<<endl;
			j++;
		}
		if(j==m)
		return (i);
		if(j==0)
		i++;
		else
		i+=j;
	}
	return -1;
}
int main()
{
	char txt[]="abcgabcjabdtabcdabef";
	char pat[]="abcd";
	int p = naivePattern(txt,pat);
	cout<<"Found at "<<p;
}
