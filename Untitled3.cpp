#include <iostream>
#include <algorithm>
#include<cstdlib>
#include<stdio.h>
using namespace std;
 
inline void scanint(int* x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}
 
int main()
{	
	while(1)
	{
		int N;
		scanint(&N);
		if(N == 0) break;
		int A[N];
 
		for(int i = 0; i < N; i++)	
			scanint(&A[i]);
 
		sort(A,A + N);
		int ans = 0;
 
		for(int i = 0; i < N-2; i++)
		{
			int I = 0;
			int r = N-i-2;
			while(I < r)
			{
				if(A[I] + A[r] < A[N-i-1])
				{
					ans += r - I;
					I++;
				}
				else r--;				
			}
		}
 
		cout << ans << endl;
		
	}
 
	return 0;
} 
