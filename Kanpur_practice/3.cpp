#include<bits/stdc++.h>
using namespace std;
/*
5 8
7 2 0 5 8
1 2
2 3
2 4
1 5
Q 1
Q 2
U 2 4
Q 1
Q 2
U 5 3
Q 1
Q 2
*/
int dfs(int i,int visited[],int skillsum[],vector<int>arr[],vector<int>skill)
{
    visited[i]=1;
    int sk = skill[i];
    for(int j=0;j<arr[i].size();j++)
    {
        if(!visited[arr[i][j]])
        {
            sk+=dfs(arr[i][j],visited,skillsum,arr,skill);
        }
    }
    skillsum[i]=sk;
    return sk;
}
void update(int skillsum[],int node,int d,int parent[])
{
    int c = parent[node];
    //cout<<c<<"Parent"<<endl;
    while(c!=0)
    {
        //cout<<"Updated"<<c<<endl;
        skillsum[c]+=d;
        c = parent[c];
    }
    skillsum[0]+=d;
}
int main()
{
    int N,S;
    cin>>N>>S;
    int parent[N];
    parent[0]=0;
    vector<int> skill;
    vector<int>arr[N];
    while(N--)
    {
        int data;
        cin>>data;
        skill.push_back(data);
    }
    N = skill.size()-1;
    while(N--)
    {
        int a,b;
        cin>>a>>b;
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
        parent[b-1]=a-1;
    }
    int visited[skill.size()];
    memset(visited,0,sizeof(visited));
    int skillsum[skill.size()];
    int ret = dfs(0,visited,skillsum,arr,skill);
   /* for(int i=0;i<skill.size();i++)
    {
        cout<<skillsum[i]<<endl;
    }*/
    int k = 0;
    while(S--)
    {
        char c;

        cin>>c;
        if(c=='Q')
        {

            int d;
            cin>>d;
            cout<<skillsum[d-1];
        }
        else
        {
            int a,b;
            cin>>a>>b;
            int d = b-skill[a-1];
            skill[a-1]=b;
            skillsum[a-1]+=d;
            update(skillsum,a-1,d,parent);
           // cout<<k<<endl;
        }
    }
}
