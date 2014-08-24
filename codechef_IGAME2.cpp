/*
    url : http://www.codechef.com/problems/IGAME

Input

The first line contains a single integer T denoting the number of test cases.
T test cases follow. Each test case consists of a single line consisting of four space separated integers m, n, p, q
respectively.

Output

For each test case print a string - either "Alice" or "Bob" (without the quotes), denoting the winner.
Constraints

1 ≤ T ≤ 1000
1 ≤ m, n ≤ 1000
0 ≤ p < m
0 ≤ q < n
Sample Input

2
1 1 0 0
2 4 1 2

Sample Output

Alice
Bob
*/
#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    if(a<b)
    return a;
    else return b;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int m,n,p,q;
        cin>>m>>n>>p>>q;
        m = m-p;
        n = n-q;
        int arr2[m+1][n+1];
        int arr[m+1][n+1];
        memset(arr,0,sizeof(arr));
        memset(arr2,0,sizeof(arr2));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                int test = 0;
                if((j==0)||(i==0))
                {
                    arr[i][j]=1;
                    arr2[i][j]=1;
                    test =1;
                }
                //FOR ALICE
                if(test ==0)
                {
                int T1 = 0,T2 = 0;
                for(int r=1;(i-r)>=0;r++)
                {
                if(arr2[i-r][j]==0)
                {
                    arr[i][j]=1;
                    T1 = 1;
                }
                if(arr[i-r][j]==0)
                {
                    arr2[i][j]=1;
                    T2 =1;
                }
                if(T1 && T2)
                break;
                }
                for(int r=1;(j-r)>=0 && (!(T1&&T2));r++)
                {
                    if(!T1)
                    {
                    if(arr2[i][j-r]==0 )
                    {
                        arr[i][j]=1;
                        T1 = 1;
                    }
                    }

                    if(!T2)
                    {
                    if(arr[i][j-r]==0 )
                    {
                        arr2[i][j]=1;
                        T2 = 1;
                    }
                    }
                    if(T1 && T2)
                    break;
                }
                int a = min(i,j);
                while(a>0 && (!(T1&&T2)))
                {
                    if(!T1)
                    {
                        if(arr2[i-a][j-a]==0 ||((i-a)==0 &&(j-a)==0))
                        {
                            arr[i][j]=1;

                        }
                    }
                    if(!T2)
                    {
                        if(arr[i-a][j-a]==0 ||((i-a)==0 &&(j-a)==0))
                        {
                            arr2[i][j]=1;

                        }
                    }

                    a--;
                }
                //for Bob
                }
            }
        }
        if(arr[m][n]==1)
        {
            cout<<"Alice"<<endl;
        }
        else
        cout<<"Bob"<<endl;
    }
}
