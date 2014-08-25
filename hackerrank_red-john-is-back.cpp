/*
https://www.hackerrank.com/challenges/red-john-is-back
*/
#include<bits/stdc++.h>
using namespace std;
int isPrime(int i)
{
    if(i==2)
    return 1;
    int q = sqrt(i);
    for(int j=2;j<=q;j++)
    {
        if(i%j==0)
        return 0;
    }

    return 1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int arr[N+1];
        int arr2[N+1];
        if(N<4)
        {
        cout<<"0"<<endl;
        }
        else{
            arr[0]=0;
            arr2[0]=0;
            arr[1]=arr[2]=arr[3]=0;
            arr2[1]=arr2[2]=arr2[3]=1;
            arr2[4]=2;
            arr[4]=1;
            if(N==4)
            {
                cout<<arr[4]<<endl;
            }
            for(int i=5;i<=N;i++)
            {
                arr2[i]=arr2[i-1]+arr2[i-4];
                if(isPrime(arr2[i]))
                {
                        //cout<<"Prime"<<arr2[i];
                        arr[i]=arr[i-1]+1;
                }
                else
                arr[i]=arr[i-1];
            }
            for(int i=0;i<=N;i++)
            cout<<"->>"<<arr[i]<<"->>"<<arr2[i]<<endl;
            cout<<arr[N]<<endl;
        }

    }
}
