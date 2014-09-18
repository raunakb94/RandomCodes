//https://www.hackerrank.com/contests/csindia/challenges/pin-problem-1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a,int b)
    {
    if(b==0)
        return a;
    else 
        return gcd(b,a%b);
}
int lcm(int a,int b)
    {
    int q = gcd(a,b);
    return ((a*b)/q);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T;
    cin>>T;
    while(T--)
        {
        int n,m;
        cin>>n>>m;
        vector<int>arr;
        int l = 1;
        while(m--)
            {
            int d;
            cin>>d;
            l = lcm(l,d);
          //  cout<<l<<endl;
        }
        cout<<n/l<<endl;
    }
    return 0;
}

