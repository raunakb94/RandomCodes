#include<bits/stdc++.h>
using namespace std;
void printIncSeq(int start,int size,int end,int level,int arr[])
{
    if(level<size)
    {
    for(int i=start+1;i<=end;i++)
    {
        arr[level]=i;
        printIncSeq(i,size,end,level+1,arr);
    }
    }
    else
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int size;
        int end;
        cin>>size>>end;
        int arr[size];
        memset(arr,0,sizeof(arr));
        printIncSeq(0,size,end,0,arr);
    }

}
