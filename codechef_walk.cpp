#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int>v;
        while(N--)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }
        int dp[v.size()];
        memset(dp,0,sizeof(dp));
        dp[v.size()-1]=v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--)
        {
            dp[i]=max(v[i],dp[i+1]+1);
        }
        cout<<dp[0]<<endl;
    }
}
