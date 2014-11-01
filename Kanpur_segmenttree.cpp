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
 
 struct seg
 {
   int f;
   int l;
   int ma;
   ll sum;
   int in;
   int de;
 };
 
 seg tree[500005],tt;
 int arr[100005];

 
void build(int start,int end,int node)
{
  if(start>end)
  return ;
  if(start==end)
  {
    tree[node].f=arr[start];
    tree[node].l=arr[start];
    tree[node].ma=arr[start];
    tree[node].sum=arr[start];
    tree[node].in=1;
    tree[node].de=1;
    return ;
  }
  int mid=(start+end)/2;
  build(start,mid,2*node+1);
  build(mid+1,end,2*node+2);
  tree[node].ma=max(tree[2*node+1].ma,tree[2*node+2].ma);
  tree[node].sum=(tree[2*node+1].sum+tree[2*node+2].sum);
  tree[node].f=tree[2*node+1].f;
  tree[node].l=tree[2*node+2].l;
  if(tree[2*node+1].in && tree[2*node+2].in)
  {
    if(tree[2*node+1].l<=tree[2*node+2].f)
    tree[node].in=1;
    else
    tree[node].in=0;
  }
  else
  tree[node].in=0;
  
  if(tree[2*node+1].de && tree[2*node+2].de)
  {
    if(tree[2*node+1].l>=tree[2*node+2].f)
    tree[node].de=1;
    else
    tree[node].de=0;
  }
  else
  tree[node].de=0;
}

seg overall(int start,int end,int x,int y,int node)
{   
    seg r1,r2,r;
    r.in=0;
    r.de=0;
    if(end<x  ||  start>y)
    return tt;
    if(x<=start && y>=end) return tree[node];
    int mid=(start+end)/2;
    r1=overall(start,mid,x,y,2*node+1);
    r2=overall(mid+1,end,x,y,2*node+2);
    r.ma= max(r1.ma,r2.ma);
    r.sum=r1.sum+r2.sum;
    r.f=r1.f;
    r.l=r2.l;
    if( r1.in && r2.in)
    {
      if(r1.l <= r2.f)
      r.in=1;
      else
      r.in=0;
    }
    else
    r.in=0;
    
    if( r1.de && r2.de)
    {
      if(r1.l >= r2.f)
      r.de=1;
      else
      r.de=0;
    }
    else
    r.de=0;
    return r;
}
void update(int start,int end,int pos,int val,int node)
{
  if(end<pos  ||  start>pos)
    return ;
    if(start==end)
    {
      tree[node].f=val;
      tree[node].l=val;
      tree[node].ma=val;
      tree[node].sum=val;
      tree[node].in=1;
      tree[node].de=1;
      return;
    }
    int mid=(start+end)/2;
    update(start,mid,pos,val,2*node+1);
    update(mid+1,end,pos,val,2*node+2);
    tree[node].ma=max(tree[2*node+1].ma,tree[2*node+2].ma);
    tree[node].sum=(tree[2*node+1].sum+tree[2*node+2].sum);
    tree[node].f=tree[2*node+1].f;
    tree[node].l=tree[2*node+2].l;
    if(tree[2*node+1].in && tree[2*node+2].in)
    {
      if(tree[2*node+1].l<=tree[2*node+2].f)
      tree[node].in=1;
      else
      tree[node].in=0;
    }
    else
    tree[node].in=0;
    if(tree[2*node+1].de && tree[2*node+2].de)
    {
      if(tree[2*node+1].l>=tree[2*node+2].f)
      tree[node].de=1;
      else
      tree[node].de=0;
    }
    else
    tree[node].de=0; 
  
}

int main()
{
  int n,M;
  si(n);
  si(M);
  memset(tree,0,sizeof(tree));
  for(int i=0;i<n;i++)
  {
    si(arr[i]);
  }
 
  build(0,n-1,0);
  
  while(M--)
  {
    char ch;
    int x,y;
    cin>>ch;
    si(x);
    si(y);
    x--;
    y--;
    seg ans;
    if(ch=='U')
    {
      update(0,n-1,x,y,0);
    }
    else
    {
       ans=overall(0,n-1,x,y,0);
    }
    if(ch=='M')
    {
      ll d=ans.ma;
      pl(d);nl;
    }
    else if(ch=='I')
    {
      int d=ans.in;
      pi(d);nl;
    }
    else if(ch=='D')
    {
      int d=ans.de;
      pi(d);nl;
    }
    else if(ch=='S')
    {
      ll d=ans.sum;
      pl(d);nl;
      
    }
  }
}
