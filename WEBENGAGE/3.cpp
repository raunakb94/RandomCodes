#include<bits/stdc++.h>
using namespace std;		
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FF(i,a,n) for(i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define MAX(a,b) ((a)>(b)?(a):(b))
long long int ABS(long long int a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second
long long int f[1000006];
long long int g[1000006];
int main() {
   // input();
    M(f,-1); M(g,0);
    f[0] = f[1] = g[0] = g[1] = 0;
    F(i,2,1000006) {
        for ( int j = i; j < 1000006; j+=i ) {
            if ( f[j] == -1 ) f[j] = i;
            g[j] += i;
        }
        g[i] -= i;
        g[i] += 1;
    }
    F(j,1,1000006) {
        f[j] = f[j-1]+f[j];
        g[j] = g[j-1]+g[j];
    }
    int t; S(t);
    while ( t-- ) {
        int n;
        S(n);
        printf("%lld\n", (f[n]+g[n])%n );
    }
    
    return 0;
}
