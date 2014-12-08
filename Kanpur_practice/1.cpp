#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int cap = 1;
        int count = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='.')
            {
                int k = 1;
                int j = i+1;
                while(s[j]=='.' && j<s.length())
                {
                    j++;
                    k++;
                }
                i = j;
                if(k>=cap)
                {
                    count++;
                    cap = k+1;
                    //cout<<cap<<endl;

                }
            }
        }
        cout<<count<<endl;
    }
}
