#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	while(str.compare("0")!=0)
	{
		int arr[str.length()];
		arr[0]=1;
		if(str[1]-'0'<=6 && str[0]-'0'<=2 &&str[1]!='0')
		arr[1]=2;
		else arr[1]=1;
		int i;
		for(i=2;i<str.length();i++)
		{
			int count = 0;
			if(str[i]!='0')	
			count = arr[i-1];
			//cout<<"Str"<<str[i]-'0'<<"->>"<<str[i-1]-'0'<<endl;
			if(str[i]-'0'<=9 && str[i-1]-'0'==1 && str[i-1]!='0')
			count +=arr[i-2];
			else if(str[i]-'0'<=6 && str[i-1]-'0'==2 && str[i-1]!='0')
			count +=arr[i-2];
			arr[i]=count;
			if(arr[i]==0)
			arr[i]=1;
			//cout<<"arr"<<arr[i];
		}
		
		cout<<arr[str.size()-1]<<endl;
		cin>>str;
	}
}

