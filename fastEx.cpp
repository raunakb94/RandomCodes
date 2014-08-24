#include<bits/stdc++.h>
using namespace std;
long long int fastExponentiation(long long int a,long long int b,long long int m)//a^bmod m
{
    int e_Temp = 0;
    long long int c = 1;
    while(e_Temp!=b)
    {
        e_Temp++;
        c = (c*a)%m;
    }
    return c;
}
int main()
{
    cout<<fastExponentiation(4,13,497);

}
