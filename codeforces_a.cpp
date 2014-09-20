#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    int M;
    cin>>N>>M;
    int max = -1;
    while(N--)
    {
        int x,y;
        cin>>x>>y;
        if(x<M ||(x==M && y == 0))
        {
            int p;
            if(y==0)
            p = 0;
            else
            p = 100 - y;
            if(p>max)
            max = p;
        }
    }
    cout<<max;

}
