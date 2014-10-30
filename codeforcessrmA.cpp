#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    vector<int>arr2;
    arr2.push_back(arr[0]+(arr[1]*arr[2]));
    arr2.push_back((arr[0]+arr[1])*arr[2]);
    arr2.push_back(arr[0]+arr[1]+arr[2]);
    arr2.push_back(arr[0]*arr[1]*arr[2]);
    sort(arr2.begin(),arr2.end());
    cout<<arr2[arr2.size()-1];
}
