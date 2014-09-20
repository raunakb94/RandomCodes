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
    cin>>T;
    vector<long long int>arr;
    while(T--)
    {
    long long int data;
    cin>>data;
        arr.push_back(data);
    }
    sort(arr.begin(),arr.end());
    long long int mincount=0;
    long long int maxcount =0;
    long long int min = LLONG_MAX;
    long long int max = 0;
    long long int i=0;long long int j=arr.size()-1;
    while(i<j)
    {
        long long int max3,min3;
        if(i+1<j)
        max3 = maxi(arr[j]-arr[i],arr[j]-arr[j-1]);
        else max3=0;
        long long int max2 = maxi(arr[i+1]-arr[i],max3);
        if(i+1<j)
        min3= maxi(arr[j]-arr[i],arr[j]-arr[j-1]);
        else min3 = LLONG_MAX;
        long long int min2 = mini(arr[i+1]-arr[i],min3);
        if(max2>max)
        {
            maxcount = 1;
            max = max2;
           // cout<<"Max"<<max<<endl;
                   }
        else if(max2==max)
        {
            maxcount++;
           // cout<<"IncMa"<<i<<endl;
        }
        if(min2<min)
        {
        mincount=1;
        min=min2;
        //cout<<"min"<<min<<endl;
        }
        else if(min2==min)
        {
            mincount++;
          //  cout<<"Inc"<<i;
        }
        if(max == min)
        {
            mincount = maxcount = maxi(max,min);
        }
        i++;
        j--;
    }
    cout<<mincount<<" "<<maxcount;
}
