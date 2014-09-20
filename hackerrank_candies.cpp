#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    vector<int>arr;
    cin>>T;
    while(T--)
    {
        int data;
        cin>>data;
        arr.push_back(data);
    }
    int arr2[arr.size()];
    arr2[arr.size()-1]=arr.size()-1;
    for(int i=arr.size()-2;i>=0;i-1)
    {
            if(arr[i]<arr[i+1])
            arr2[i]=i+1;
            else if(arr[i]==arr[i]+1)
            arr2[i]=arr2[i+1];
            else
            arr2[i]=i;
    }
    int arr3[arr.size()];
    arr3[0]=arr2[0];
    for(int i=1;i<)
}
