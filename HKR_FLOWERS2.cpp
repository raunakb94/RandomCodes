#include<iostream>
//#include<conio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int N, K;
    cin >> N >> K;
    int C[N];
   for(int i = 0; i < N; i++){
   	
   	cin>>C[i];
      //C.push_back(data);
   }
   sort(C,C+N, greater<int>());
   int result = 0;
   for(int p=0;p<K;p++)
   {
   int j = 0;
   for(int i=p;i<N;i=i+K)
   {	//cout<<"C"<<C[i];
	   	result += C[i]*(j+1);
	   	//cout<<C[i]*(j+1);
	   	j++;
   }
	}
   cout << result << "\n";
   
   return 0;
}
