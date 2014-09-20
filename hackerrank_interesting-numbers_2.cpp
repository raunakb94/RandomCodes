#include<bits/stdc++.h>
using namespace std;
long long int mini(long long int a,long long int b)
{
    if(a<b)
    return a;
    else return b;
}
long long int maxi(long long int a,long long int b)
{
    if(a>b)
    return a;
    else return b;
}
int main()
{
    long long int T;
    map<int,int>map1;
    cin>>T;
    vector<long long int>arr;
    while(T--)
    {
    long long int data;
    cin>>data;
        arr.push_back(data);
        map1[data]++;
        //cout<<map1[data];
    }
    sort(arr.begin(),arr.end());
    long long int max1;
    if(arr[0]!=arr[arr.size()-1])
     max1 = map1[arr[0]]*map1[arr[arr.size()-1]];
    else
    max1 = (map1[arr[0]])*(map1[arr[0]]-1)/2;
    long long int min1,min2;
    min1 =min2= LLONG_MAX;
    long long int diff = LLONG_MAX;
    for(int i=0;i<arr.size()-2;i++)
    {
        long long int difftemp = arr[i+1]-arr[i];
        if(difftemp<diff)
        {
            diff = difftemp;
            min1 = arr[i];
            min2 = arr[i+1];
        }
    }
    long long int minc;
    if(min1!=min2)
    minc = map1[min1]*map1[min2];
    else
    minc = (map1[min1])*(map1[min1]-1)/2;

    cout<<minc<<" "<<max1<<endl;
    //cout<<mincount<<" "<<maxcount;
}
