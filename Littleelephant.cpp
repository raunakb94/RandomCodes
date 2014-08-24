#include<bits/stdc++.h>
using namespace std;
int total = 0;
int permute(int arr[],vector<int> arr2[],int depth,int count)
{
	//cout<<"reached here";
	//cout<<(depth);
	if(depth == count+1)
	{
		total++;
		//cout<<"Increased";
		return 0;
	}
	//cout<<"arr2"<<arr2[depth].size()<<endl;
	for(int i=0;i<arr2[depth].size();i++)
	{
		//cout<<"-->"<<arr2[depth][i];
		if(arr[arr2[depth][i]]!=1)
		{
		//cout<<"selectd"<<arr2[depth][i]<<endl;
		arr[arr2[depth][i]] = 1;
		permute(arr,arr2,depth+1,count);
		//cout<<"Returnde";
		arr[arr2[depth][i]]=2;
		}
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		::total = 0;
		int arr[101];
		memset(arr,0,101);
		
		
		int count;
		cin>>count;
		vector<int>arr2[count+1];
		int i =1;
		char ch[50000];
		gets(ch);
		while(i<=count)
		{
			//cout<<"Input";
			//cout<<"i"<<i<<endl;
			
			gets(ch);
			//cout<<"Inp done";
			//puts(ch);
			char *pat = strtok(ch," ");
			while(pat!=NULL)
			{
				int j = atoi(pat);
				
				//cout<<endl<<j<<endl;
				pat = strtok(NULL," ");
				arr2[i].push_back(j);
				//arr[j]=2;
			}
			//cout<<"done";
		i++;		
		}
		int perm[count+1];
		permute(arr,arr2,1,count);
		cout<< ::total<<endl;
	}
}
