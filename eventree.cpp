#include<bits/stdc++.h>
using namespace std;
int count =0;
int dfs(vector<int>arr[],int i,int visit[])
{
    //cout<<"Hello";
    int q =1;
    //cout<<"In Node"<<i<<endl;
    for(int j=0;j<arr[i].size();j++)
    {
        if(visit[arr[i][j]]==0)
        {
        //cout<<"Going to"<<arr[i][j]<<endl;
        visit[arr[i][j]]=1;
        q += dfs(arr,arr[i][j],visit);
        }
    }
    if(q%2==0 && i!=0)
        {
        //cout<<q<<"found";
        ::count++;
        //cout<<"Increased"<<::count;
        return 0;
        }
    return q;
}
int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> arr[N];
    int visited[N];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<M;i++)
    {
        int p,q;
        cin>>p>>q;
        arr[p-1].push_back(q-1);
        arr[q-1].push_back(p-1);
    }
    /*for(int i=0;i<N;i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }*/
    visited[0]=1;
    //cout<<"Hello";
    dfs(arr,0,visited);
    cout<<::count;
}
