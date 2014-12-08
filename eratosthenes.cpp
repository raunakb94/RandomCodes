#include<iostream>
#include<cmath>
using namespace std;
int prime(long int a)
{
	if(a%2==0)
	{
		return 0;
	}
	else
	{
	int b=sqrt(a);
	for(int i=3;i<=b;i++)
	{
		if(a%b==0)
		return 0;
		
	}
	}
	return 1;
}//Limits upto2147483647

void sieve_eratosthenes(int max)
{
	int *checker = new int[max+1];
	checker[0]=0;
	checker[1]=0;
	for(int p=0;p<=max+1;p++)
	{
		checker[p]=1;
	}
	cout<<checker[6]<<endl;
	for(int n=2;n<=max;n++)
	{
		if(checker[n]==1)
			for(int m=2;m*n<=max;m++)
				checker[m*n]=0;
	}
	for(int i=2;i<=max;i++)
	{
		if(checker[i]==1)
			cout<<i<<endl;
	} 
}
int main()
{
	long int c;
	cin>>c;
	int check=prime(c);
	if(check==0)
	cout<<"Nt Prime \n ";
	else 
	cout<<"prime \n";
	cout<<"enter a numner";
	int sieve;
	cin>>sieve;
	sieve_eratosthenes(sieve);
return 0;
}
