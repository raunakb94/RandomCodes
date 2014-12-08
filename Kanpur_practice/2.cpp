#include<bits/stdc++.h>
using namespace std;
long long int m(string str)
{
   cout<<str<<endl;
    long long int max = 0;
    for(int i=0;i<str.length();i++)
    {
        if(isdigit(str[i]))
        {
            char c = str[i++];
           long long int a = atoi(&c);
            while(isdigit(str[i]))
            {
                char cc = str[i];
                a = a*10+ atoi(&cc);
                cout<<a<<endl;
                i++;
            }
            if(a>max)
            max = a;
        }
    }
    return max;
}
int main()
{
    string s;
    cin>>s;
    long long int max = m(s);
    for(int i=0;i<s.length();i++)
    {
        if(isalpha(s[i]))
        {
            string str;
            str.push_back('9');
            i++;
            while(isdigit(s[i]))
            {
                char c = s[i];
                str.push_back(c);
                i++;
            }
        long long int a = m(str);
        if(a>max)
        max = a;
        }
    }
    cout<<max;
}
