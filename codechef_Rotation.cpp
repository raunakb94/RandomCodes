#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
vector<int> arr;
while(n--)
{
    int d;
    cin>>d;
    arr.push_back(d);
}
//cout<<arr.size()<<"Size"<<endl;
vector<int> ch;
int sum = 0;
while(m--)
{
    char c;
    int q;
    cin>>c>>q;
    if(c == 'C')
    {
        sum+=q;
    }
    else if(c=='A')
    {
        sum+=(-q);
    }
    else if(c=='R')
    {
        int arr2[arr.size()];
        for(int i=1;i<=arr.size();i++)
        {
            arr2[i-1]=i-1;
            //cout<<"i"<<"->>"<<arr2[i]<<endl;
        }
        if(sum!=0)
        {
            int rem = sum%arr.size();
  //          cout<<rem<<"Rem";
            int j=arr.size()-1;
            for(int i=0;i<arr.size();i++)
            {
                arr2[i]=(arr2[i]+rem)%arr.size();
                cout<<"i"<<"->>"<<arr2[i];
            }
            for(int i=0;i<arr.size();i++)
            {
                if(arr2[i]==q-1)
                cout<<arr[i];
            }
            //cout<<arr[j]<<endl;
        }
        if(sum == 0)
        {
            cout<<arr[q-1];
        }
        cout<<endl;
    }
}
}
