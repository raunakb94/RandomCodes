#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        int arr[26];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<str.length();i++)
        {
            arr[str[i]-97]++;
        }
        int count = 0;
        for(int i=0;i<26;i++)
        {
            if(arr[i])
            ++count;
        }
        cout<<count<<endl;
    }
}
