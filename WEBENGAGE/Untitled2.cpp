#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
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
#include <map>
#include <cassert>
#define LOGMAXN 25
#define MAXN 100009
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define S1(x) scanf("%lld",&x)
#define epsilon 0.000001

using namespace std;

ill a[100];

int main()
{

   // freopen ("input.txt", "r", stdin);

    a[0] = 1LL;
    for (ill i = 1; i <= 50; i++) {
        a[i] = a[i-1]*2LL;
    }

    ill t;
    cin >> t;
    while (t--) {
        ill n;
        ill i,sum=0;
        cin >> n;

        for (i = 1; i <= n; i++) {
            sum+=a[n-1]*i;
        }
        cout << sum << endl;
    }


    return 0;
}
