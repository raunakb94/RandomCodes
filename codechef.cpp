#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <numeric>
#include <limits>
#include <iterator>
using namespace std;


const int INF=(1<<30)-1;
const int DIRX[]={-1, 0, 0, 1,-1,-1, 1, 1}, DIRY[]={ 0,-1, 1, 0,-1, 1,-1, 1};
const double ERR=1e-11, PI=(2*acos(0.0));


#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
template<class T> inline T MIN(T a,T b) {return ((a<b)?(a):(b));}
template<class T> inline T MAX(T a,T b) {return ((b<a)?(a):(b));}
template<class T> inline T ABS(T a) {return ((a<(T)0)?(-a):(a));}
template<class T> inline void checkMIN(T& a,T b) {if(b<a) a=b;}
template<class T> inline void checkMAX(T& a,T b) {if(a<b) a=b;}
template<class T> T SQR(T x) {return (x*x);}
template<class T> T GCD(T a,T b) {if(!b) return a; else return GCD(b,a%b);}
template<class T> T fastPow(T Base,T Power)
{T Result=(T)1; while(Power>0) {if(Power&(T)1)Result*=Base; Power>>=1; Base*=Base;} return Result;}
template<class T> T modPow(T Base,T Power,T Mod)
{T Result=(T)1; while(Power>0) {if(Power&(T)1)Result=(Result*Base)%Mod; Power>>=1;Base=(Base*Base)%Mod;}return (Result%Mod);}
inline int CompareDouble(double x,double y,double err=ERR) { double d=x-y; if(d>err) return 1; if(d<-err) return -1; return 0;}

#define DUMP(x)     cout << #x << " = " << x << endl;
#define rep(x,n)	for(x=0;x<(int)(n);x++)
#define fori(x,a,b)	for(x=(a);x<=(b);x++)
#define ford(x,a,b)	for(x=(a);x>=(b);x--)
#define Mem(X,byte)	memset((X),(byte),sizeof(X))
#define all(X)		(X).begin(),(X).end()
#define Size(X)		((int)(X).size())
#define Each(X,itr)	for( __typeof((X).begin()) itr=(X).begin(); itr!=(X).end(); itr++)
#define Contains(X,item)	((X).find(item) != (X).end())
#define Contains_n(X,item)	(find((X).begin(),(X).end(),(item)) != (X).end())
#define PB	push_back
#define MP	make_pair
#define fs	first
#define sc	second


typedef unsigned long long ULL;
typedef long long int      LL;
typedef stringstream   SS;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL>     VL;
typedef vector<int>    VI;
typedef pair<int,int>  Pii;
int main()
{
	LL no_test;LL a,b;
	cin>>no_test;
	for(LL p=0;p<no_test;p++)
	{
		cin>>a>>b;
		if(b==0)
		cout<<0<<" "<<a<<endl;
		else
		cout<<a/b<<" "<<a%b<<endl;
	}
	
	return 0;
}
