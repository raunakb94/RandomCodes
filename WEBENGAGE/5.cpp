#include<bits/stdc++.h>
#define ill long long int
#define F(i,a,n) for(i=(a);i<(n);++i)
#define V(x) vector<x>
using namespace std;

int a[101];
int dp[101][10001];
int s;
int n;
int x1;
int calc(int i, int l)			
{
    if (i == n) {
     //   cout << left << " " << s-left << endl;
        if (l >= 0 && s-(x1-l) <= x1) return 1;
        return 0;
    }
    int &res = dp[i][l];
    if (res != -1) return res;
    res = 0;
    res = calc(i+1, l);
    if (l-a[i] >= 0) res = max (res, calc(i+1, l-a[i]));
    return res;
}

int main()
{

   // freopen ("input.txt", "r", stdin);

    int T;
    cin >> T;
    while (T--) {
        int X;
        cin >> n >> X;
        x1 = X;
        X = 2*X;

        int i;
        int xx=X/2;
        s = 0;
        memset (dp, -1, sizeof(dp));
        xx = min (xx, 10000);


        bool test = true;

        F (i, 0, n) {
            int x;  cin >> x;
            a[i] = x;
            s+=x;
        }
		sort (a,a+n);
        test = calc(0, xx);
        
		
		if (test) cout << "YES" << endl;
        else cout << "NO" << endl;


    }


    return 0;
}
