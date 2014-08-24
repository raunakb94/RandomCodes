#include<bits/stdc++.h>
using namespace std;
char arr[] = "abcdefghijklm";
int cc;
int var;
void permute(char arr2[],int arr3[],int depth,int count)
    {
   // cout<<"Hello";
    if(depth == 13)
    {::cc++;
     if(::cc==count)
     {cout<<arr2<<endl;
     ::var =1;
     }//cout<<arr2<<endl;
     
    }
    for(int i=0;i<13;i++)
        {
        if(arr3[i]!=1 && ::var ==0)
            {
            arr2[depth]=arr[i];
            arr3[i]=1;
            //cout<<"Selected"<<i<<arr2[depth];
            permute(arr2,arr3,depth+1,count);
            arr3[i]=0;
        }
    }
}
int main()
    {
    int t;
    cin>>t;
    while(t--)
        {
        char arr2[13];
        arr2[0]='/0';
        int arr3[13];
        memset(arr3,0,sizeof(arr3));
        long long int c;
        cin>>c;
        ::cc=0;::var=0;
        permute(arr2,arr3,0,c);
    }
}
