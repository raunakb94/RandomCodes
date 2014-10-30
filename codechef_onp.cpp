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
    stack<char>st1;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='+'||str[i]=='-'||str[i]=='^'||str[i]=='*'||str[i]=='/')
        st1.push(str[i]);
        else if(str[i]==')' && !st1.empty())
        {

            cout<<st1.top();
            st1.pop();
        }
        else if(isalpha(str[i]))
        cout<<str[i];
    }
    cout<<endl;
    }


}
