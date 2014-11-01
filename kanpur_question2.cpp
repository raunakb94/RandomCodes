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
#define nl    printf("\n")
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


struct tt
{
  int strt;
  int end;
  int ch;
};
tt v[100];
int main()
{
  int t,p,q;
  si(t);
  while(t--)
  {
  string s;
  cin>>s;
  si(p);
  si(q);
  int m[28]={0};
  for(int i=0;s[i];i++)
  {
    m[s[i]-97]++;
    
  }
  for(int i=0;i<26;i++)
  {
    m[i]*=p;
  }
  int last=0;char ans=' ';
  for(int i=0;i<26;i++)
  {
    v[i].strt=last+1;
    v[i].end=last+m[i];
    v[i].ch=(char)(i+97);
    last=last+m[i];
  }
  int n;
  while(q--)
  {
    si(n);ans=' ';
    for(int i=0;i<26;i++)
    {
      if(n>=v[i].strt && n<=v[i].end)
      {
        ans=v[i].ch;
      }
    }
    if(ans==' ')
     printf("-1");
    else
    {
      cout<<ans;
    }
     nl;
    
  }
}
  
}
