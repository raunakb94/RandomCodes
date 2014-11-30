#include<iostream>
using namespace std;
int main()
{
int num;
cin>>num;
while(num>0)
{long long int c,d;
 cin>>c>>d;
 long long int res;
 res=(c*d)-c-d;
 cout<<res<<endl;
 num--;
}
return 0;
} 
