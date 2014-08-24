#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
    {
    if(a>b)
    return a;
    else return b;
        
}
int main()
    {
    int T;
    cin>>T;
    while(T--)
        {
        int N;
	cin>>N;
        int arr[N];
        
        int i=0;
        
        while(i<N)
         {
		int data;
            cin>>data;
	arr[i]=data;
            i++;
	cout<<"Goo";
        }
        cout<<"Entered";
        int arr2[N];
        arr2[N-1]=arr[N-1];
        for(int i=N-2;i>=0;i--)
            {
            arr2[i]=max(arr[i],arr2[i+1]);
		cout<<i<<"->>"<<arr2[i]<<endl;
        }
        int profit =0;
        for(int i=0;i<N;i++)
            {
            profit+=max(0,arr2[i]-arr[i]);
        }
        cout<<profit<<endl;
    }
    
}
