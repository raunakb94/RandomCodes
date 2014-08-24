#include<bits/stdc++.h>
using namespace std;
int SUM = 0;
int min = INT_MAX;
int absDiff(int a,int b)
{
    if(a>b)
    return a-b;
    else
    return b-a;
}
int dfs(vector<int>arr[],int visited[],int i,int sum[])
{
    //cout<<"Hello";
    int q =sum[i];
   for(int j=0;j<arr[i].size();j++)
   {
        if(!visited[arr[i][j]])
        {
            visited[arr[i][j]]=1;
            q+=dfs(arr,visited,arr[i][j],sum);
        }
   }
   int diff = absDiff(::SUM,2*q);
   if(diff<(::min))
   ::min = diff;
   return q;
}
int main()
{
    int N;
    cin>>N;
    int visited[N];
    int sum[N];
    //int SUM=0;
    vector<int> arr[N];
    int i=0;
    while(i<N)
    {
    int s;
    cin>>s;
    sum[i]=s;
    (::SUM)+=s;
    i++;
    }
    i=0;
    while(i<N-1)
    {
    int p,q;
    cin>>p>>q;
    arr[p-1].push_back(q-1);
    arr[q-1].push_back(p-1);
    i++;
    }
    memset(visited,0,sizeof(visited));
    visited[0]=1;
    dfs(arr,visited,0,sum);
    cout<<::min;
}
