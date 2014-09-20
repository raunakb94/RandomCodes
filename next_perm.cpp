#include<bits/stdc++.h>
using namespace std;
int count =0;
map<string,int> m1;
void nextperm(string str,int test[],string str2)
{
    if(str2.length() == str.length())
    {
    if(m1.find(str2)==m1.end())
    {
        cout<<str2<<endl;
        ::count++;
        m1.insert(pair<string,int>(str2,1));
    }
    else
    cout<<"Repeated"<<str2<<endl;
    }
    else{
        for(int i=0;i<str.length();i++)
        {
            if(test[i]==0)
            {
                test[i]=1;
                str2.push_back(str[i]);
                nextperm(str,test,str2);
                str2.pop_back();
                test[i]=0;

            }
        }
    }
}
int main()
{
    string str;
    getline(cin,str);
    cout<<str<<endl;
    int test[str.length()];
    memset(test,0,sizeof(test));
    //test[0]=1;
    string str2;
    //str2.push_back(str[0]);
    nextperm(str,test,str2);
    cout<<::count;
}
