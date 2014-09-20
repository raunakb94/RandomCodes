#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<int>arr;
    while(N--)
    {
        int data;
        cin>>data;
        arr.push_back(data);
    }
    int cost = arr[0];
    int energy = cost;
    for(int i=0;i<arr.size()-1;i++)
    {
        if(energy<arr[i+1])
        {
            cost +=(arr[i+1]-energy);
            energy = arr[i+1];
        }
        else
        energy += (arr[i]-arr[i+1]);
    }
    cout<<cost;
}
