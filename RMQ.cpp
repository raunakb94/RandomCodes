#include<iostream>
#include<vector>
using namespace std;
int rmq(int a[]);
int main()
{
	int arr[]={2,4,3,1,6,7,8};
	int res = rmq(arr);
	cout<<res;
	return 0;
}

int rmq(int a[])//<O(N3), O(1)> complexity
{
	int mat[7][7];
	for(int i=0;i<7;i++)
	mat[i][i]=i;
	for(int i=0;i<7;i++)
	{
		for(int j=i+1;j<7;j++)
		{
			if(a[mat[i][j-1]]<a[j])
			mat[i][j]=mat[i][j-1];
			else
			mat[i][j]=j;
		}
	}
	return mat[4][6];
}

int segtree(int node,int b,int e,int M[maxInd],int A[maxN],int n)



