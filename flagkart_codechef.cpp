#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int count=0;
void dfs(vector< vector<int> > arr,int *arrn,vector<int> b,int ne,int num);
vector<int> nodes;
int main()
{
	int num_test;
	cin>>num_test;
	while(num_test>0)
	{
		int num,old,ne;
		cin>>num>>old>>ne;
		//vector< vector<int> > *arr=new vector<vector<int> >[num+1];
		 vector< vector<int> > arr(num+1);
		for(int i=1;i<=num;i++)
		{
			arr[i].push_back(i);
		}
		for(int i=1;i<=num;i++)
		{
			if(i!=old)
			{
			int key;
			cin>>key;
			arr[i].push_back(key);
			arr[key].push_back(i);
			}
		}
		int *arrn=new int[num+1];
		std::fill(arrn,arrn+num+1,0);
		nodes.clear();
		::count=0;
		dfs(arr,arrn,arr[ne],ne,num);
		for(int i=1;i<=num;i++)
		{
			if(i!=ne)
			cout<<arrn[i]<<" ";
			
		}
		cout<<endl;
		num_test--;
	}
}

void dfs(vector< vector<int> > arr,int *arrn,vector<int> b,int ne,int num)
{
	if(::count == num-1)
	return;
	int n=b[0];
	//cout<<"-- "<<n<<endl;
	nodes.push_back(n);
	sort(nodes.begin(),nodes.end());
	for(int i=1;i<b.size();i++)
	{
		
		if(arrn[b[i]]==0 && b[i]!=ne)
		{
			//cout<<b[i]<<"b"<<endl;
			arrn[b[i]]=n;
			//cout<<arrn[b[i]]<<"Content"<<endl;
			::count++;
			//cout<<::count<<"count"<<endl;
		}
	}
	for(int i=1;i<b.size();i++)
	{
		if(b[i]!=ne && !(binary_search(nodes.begin(),nodes.end(),b[i])))
		{
		//cout<<b[]<<"going to node"<<endl;
		dfs(arr,arrn,arr[b[i]],ne,num);
		}
	}
	return ;
	
}
