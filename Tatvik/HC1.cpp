#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        long long int M;
        cin>>N;
        vector<int> arr;
        int sum = 0;
        while(N--)
        {
            int data;
            cin>>data;
            arr.push_back(data);
            sum+= data;
        }
        cin>>M;
        int q = M/sum;
        M = M- M*q;
        sum = 0;
        for(int i=0;i<arr.size();i++)
        {
            sum=sum + arr[i];
            if(sum >= M)
            {
                cout<<i+1<<endl;
                break;
            }
        }
    }
}
