#include<bits/stdc++.h>
using namespace std;
vector<int>arr[100000];
int visited[100000];
int depth[100000];
int H[100000];
int maxi(int a,int b)
{
    if(a>b)
    return a;
    else return b;
}
int precompute(int i)
{
    //cout<<endl<<"Hello->>"<<i;
    int links = arr[i].size();
    vector<int>tempArr;
    vector<int>height;
    //memset(tempArr,0,sizeof(tempArr));
    int pp = 0;
    for(int j=0;j<arr[i].size();j++)
    {
        if(!visited[arr[i][j]])
        {
            visited[arr[i][j]]=1;
            int q = precompute(arr[i][j]);
            tempArr.push_back(q);
            height.push_back(H[arr[i][j]]);
            pp = j;
            //cout<<i<<"piushd"<<H[arr[i][j]]<<"  "<<(arr[i][j])<<endl;
        }
    }
    sort(tempArr.begin(),tempArr.end());
    sort(height.begin(),height.end());
    /*for(int j=0;j<height.size();j++)
    {
        cout<<"node"<<i<<height[j]<<"  "<<tempArr[j]<<endl;
    }*/
    if(tempArr.size()==0)
    {depth[i]= 0;
    H[i]=0;
    return 0;
    }
    int max1 = 0;
    int max2 =0;
    if(tempArr.size()==1)
    {
    max1 = tempArr[0];
    //depth[i]=tempArr[0];
    max2=height[0]+1;
    //depth[i]=maxi(max2,max1);
    }
    if(tempArr.size()>=2)
    {
        max2=height[height.size()-1]+height[height.size()-2]+2;
        max1 = tempArr[tempArr.size()-1];
    }
    //cout<<"returnde"<<depth[i];
    depth[i]=maxi(max2,max1);
    H[i]=height[height.size()-1]+1;
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
memset(H,0,sizeof(H));
int root;
cin>>root;
visited[root-1]=1;
precompute(root-1);
int q;
cin>>q;

/*for(int i=0;i<N;i++)
{
cout<<endl<<i<<"depth"<<depth[i]<<"Height"<<H[i];
}*/
while(q--)
{
    int r;
    cin>>r;
    cout<<depth[r-1]<<endl;
}
return 0;
}
