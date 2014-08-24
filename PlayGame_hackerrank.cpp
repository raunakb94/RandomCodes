#include<bits/stdc++.h>
using namespace std;
long long int max(long long int a,long long int b,long long int c)
    {
    if((a>b)&&(a>c))
        return a;
    if((c>b)&&(c>a))
        return c;
    if((a==b)&&(a>c))
        return a;
    if((b==c)&&(b>a))
        return b;
    if((c==a)&&(a>b))
        return c;
    else return b;
}
int main()
    {
    int T;
    cin>>T;
    while(T--)
        {
        int N;
        cin>>N;
        int n=N;
        vector<long long int> arr;
        while(N--)
            {
            long long int data;
            cin>>data;
            arr.push_back(data);
        }
        reverse(arr.begin(),arr.end());
        long long int sum[n];
        sum[0]=arr[0];
        for(int i=1;i<n;i++)
            {
            sum[i]=sum[i-1]+arr[i];
        }
        long long int dp[n];
        dp[0]=arr[0];
        dp[1]=arr[1]+arr[0];
        dp[2]=arr[0]+arr[1]+arr[2];
        for(int i=3;i<n;i++)
            {
            dp[i]=max((sum[i-1]-dp[i-1]+arr[i]),(sum[i-2]-dp[i-2]+arr[i]+arr[i-1]),(sum[i-3]-dp[i-3]+arr[i]+arr[i-1]+arr[i-2]));
        }
        cout<<dp[n-1]<<endl;
    }
}
