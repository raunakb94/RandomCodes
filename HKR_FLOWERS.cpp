#include<iostream>
//#include<conio.h>
#include<algorithm>
#include<vector>
using namespace std;
void increase(vector<int>* arr,int p,int n)//increase cost for the flowers in the ith round of buying
{
	
}
int main()
{
	int N, K;
    cin >> N >> K;
    vector<int> C(N);
   for(int i = 0; i < N; i++){
   	int data;
   	cin>>data;
      C.push_back(data);
   }
   sort(C.begin(),C.end());
   for(int i = 0; i < N; i++){
   	cout<<C[i]<<endl;
   }
   int j = 0;
   int selected = 0;
   int result=0;
   int n=N;
   while(selected != N)
   {	
   		for(int i=0;i<n;i++)
		{
		C[i] = (j+1)*(C[i]);
		}
   		for(int i=0;i<K && selected!=N;i++)
   		{
   			result +=C.back();
//	cout<<"(("<<C.back()<<"))";
   			C.pop_back();
   			n--;
		   	++selected;
   		}
//	cout<<endl;
	 		j++;
   }
   
   cout << result << "\n";
   
   return 0;
}
