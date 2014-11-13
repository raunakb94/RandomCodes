#include<bits/stdc++.h>
using namespace std;

#define fOr(i,n) for(int i=0;i<n;i++)
#define For(i,n) for(int i=1;i<=n;i++)
#define ss(a) scanf("%s",a)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pi(a) printf("%d ",a)
#define pl(a) printf("%lld ",a)
#define ps(a) printf("%s ",a)
#define nl printf("\n")
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define INF 2000000000
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
const double eps=1e-9;
const double PI=2*acos(0.0);
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

int main()
{
ll h,d,u,k,ans;
int t;
si(t);
while(t--)
{
sl(h);
sl(u);
sl(d);
ll tt=(u)-(h%u);
if(tt==u)
tt=0;
ll md=(u*d);
ans=tt%md;
if(ans%d!=0)
{
ans=-1;

}
else
{
k=ans/d;
ans=((d*k)+h);
ans/=u;
ans+=k;
}
pl(ans);nl;
}
}
