#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <complex>
using namespace std;
#define ull unsigned long long
#define ill long long int
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
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second
/* Relevant code begins here */
/* Input from file or online */
void input() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
}
/* Input opener ends */
int main() {
    input();
    int t; cin >> t;
    while (t-- ) {
        string s; cin >> s;
        vector<int> v;
        int idx = 0, c = 0;
        while ( idx < s.size() ) {
            if ( s[idx] == '|' ) {
                if ( c ) v.pb(c);
                c = 0;
            } else c++;
            idx++;
        }
        if ( c ) v.pb(c);
        if ( v.size() == 0 || v[0] == s.size() ) {
            printf("Bob\n");
            continue;
        }
        int x = 0;
        F(i,0,v.size()) x ^= v[i];
        if ( x == 0 ) printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}
