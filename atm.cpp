#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	
	int x;
	float y;
	cin>>x>>y;
	if(x+0.50>y || x%5!=0)
	{
		std::cout<<std::fixed<<std::setprecision(2)<<y;
	}
	else
	{
		y = y-x-0.50;
		std::cout<<std::fixed<<std::setprecision(2)<<y;
	}

	return 0;
}
