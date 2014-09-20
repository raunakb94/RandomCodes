#include<bits/stdc++.h>
using namespace std;
vector<int>arr[100000];
int visited[100000];
int depth[100000];
int precompute(int i)
{
    //cout<<endl<<"Hello->>"<<i;
    int links = arr[i].size();
    vector<int>tempArr;
    //memset(tempArr,0,sizeof(tempArr));
    for(int j=0;j<arr[i].size();j++)
    {
        if(!visited[arr[i][j]])
        {
            visited[arr[i][j]]=1;
            tempArr.push_back(1+precompute(arr[i][j]));
        }
    }
    sort(tempArr.begin(),tempArr.end());
    if(tempArr.size()==0)
    {depth[i]= 0;
    }
    if(tempArr.size()==1)
    depth[i]=tempArr[0]-1;
    if(tempArr.size()>=2)
    depth[i]=tempArr[tempArr.size()-1]+tempArr[tempArr.size()-2];
    //cout<<"returnde"<<depth[i];
    return depth[i];
    //cout<<"Hello";
}
int main()
{
    int N;
    cin>>N;
    int i = 0;
    //vector<int>arr[N];
    for(i=0;i<N-1;i++)
    {
        int p,q;
        cin>>p>>q;
        arr[p-1].push_back(q-1);
        arr[q-1].push_back(p-1);
        //cout<<"Success";
    }

memset(visited,0,sizeof(visited));
int root;
cin>>root;
visited[root-1]=1;
precompute(root-1);
int q;
cin>>q;
for(int i=0;i<N;i++)
{
cout<<endl<<"depth"<<depth[i];
}
while(q--)
{
    int r;
    cin>>r;
    cout<<depth[r-1]<<endl;
}
return 0;
}
