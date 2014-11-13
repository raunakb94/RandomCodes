#include<bits/stdc++.h>
using namespace std;
int get(string s)
{
    int size = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='C')
        {
            int count = 1;
            i++;
            while(s[i]=='C')
            {
            count++;
            i++;
            }
            if(count>size)
            size = count;
        }
    }
    return size;

}
int main()
{
    int N;
    vector<string>arr;
    cin>>N;
    while(N--)
    {
        string s;
        cin>>s;
        arr.push_back(s);
    }
    int x=0,y=0;
    for(int i=0;i<arr.size();i++)
    {
        int p = get(arr[i]);
        if(p>x)
        x = p;
    }
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i][arr[i].length()-1]=='C' && arr[i+1][0]=='C')
        {
            string temp;
            temp = arr[i];
            temp.append(arr[i+1]);
            int p = get(temp);
            if(p>y)
            y = p;
        }
    }
    cout<<x<<" "<<y;
}
