#include<bits/stdc++.h>
using namespace std;
vector<int>convert(string str,int i,int j)
{
	vector<int>arr;
	for(int p=i;p<=j;p++)
	{
		int q = str[p]-'0';
		arr.push_back(q);
		//cout<<q;
	}
	//cout<<endl;
	return arr;
}
vector<int> add(vector<int>arr1,vector<int>arr2)
{
	
	
		int carry = 0;
		int k,l;
		for(k = arr1.size()-1,l = arr2.size()-1;k>=0,l>=0;k--,l--)
		{
			int sum = arr1[k]+arr2[l]+carry;
			carry = sum/10;
			arr1[k]=sum%10;
		}
		
	
			while(k>=0)
			{
			int s = arr1[k]+carry;
			arr1[k]=s%10;
			carry = s/10;
			k--;
			}
		
		if(carry>0)
		{
			arr1.insert(arr1.begin(),carry);
		}
		return arr1;
	
}
vector<int> sub(vector<int>arr1,vector<int>arr2)
{
		int carry = 0;
		int k,l;
		for(k = arr1.size()-1,l = arr2.size()-1;k>=0,l>=0;k--,l--)
		{
			int sub = arr1[k]-arr2[l]-carry;
			if(sub>=0)
			{
				arr1[k]=sub;
				carry = 0;
			}
			else
			{
				sub = arr1[k]+10-arr2[l]-carry;
				carry = 1;
				arr1[k]=sub;
			}
			
		}
		
			while(k>=0)
			{
			int s = arr1[k]-carry;
			if(s>=0)
			{
				arr1[k]=s;
				carry = 0;
				break;
			}
			else
			{
				s = s+10;
				arr1[k]=s;
				carry = 1;
			}
			k--;
			}
		
		
		if(carry>0)
		{
			arr1.insert(arr1.begin(),carry);
		}
		
		
		return arr1;
	
}
vector<int>multiply(vector<int>arr1,vector<int>arr2)
{
	int count = 0;
	int y=1;
	for(int x=arr2.size()-1;x>=0;x--)
	{
		count = count+arr2[x]*(y);
		y = y*10;
	}
	vector<int>arr3 = arr1;
	while(count-- >1)
	{
		arr1 = add(arr1,arr3);	
	}
		return arr1;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		vector<int>arr;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='*')
			{	
				vector<int>arr1 = convert(str,0,i-1);
				vector<int>arr2 = convert(str,i+1,str.size()-1);
				if(arr1.size()>=arr2.size())
				arr = multiply(arr1,arr2);
				else
				arr = multiply(arr2,arr1);
			}//multiply(str,i-1,i+1);
			else if(str[i]=='+')
			{
				//cout<<i;
				vector<int>arr1 = convert(str,0,i-1);
				vector<int>arr2 = convert(str,i+1,str.size()-1);
				if(arr1.size()>=arr2.size())
				arr = add(arr1,arr2);
				else
				arr = add(arr2,arr1);
				
			}
			else if(str[i]=='-')
			{
				vector<int>arr1 = convert(str,0,i-1);
				vector<int>arr2 = convert(str,i+1,str.size()-1);
				arr = sub(arr1,arr2);
			}//sub(str,i-1,i+1);
		}
		int x = 0;
		while(arr[x]==0)
		x++;
		for(;x<arr.size();x++)
		cout<<arr[x];
		cout<<endl;		
	}
}

