#include<bits/stdc++.h>
using namespace std;
int lcs(string str1,string str2,int arr[1000][1000])
{
memset(arr,0,sizeof(arr));
    for(int i=0;i<=str1.length();i++)
    {
        for(int j=0;j<=str2.length();j++)
        {
            if(i==0||j==0)
            {
                arr[i][j]==0;
            }
            else if(str1[i-1]==str2[j-1])
            {
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else
            arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    }
    return arr[str1.length()][str2.length()];
}
int main()
{
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    int dp[1000][1000];
    clock_t t = clock();
    cout<<lcs(str1,str2,dp)<<endl;
    t = clock()-t;
    cout<<"Time"<<float(t)/CLOCKS_PER_SEC;
}
