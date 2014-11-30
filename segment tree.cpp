#include<iostream>
#include<cmath>
using namespace std;
template<class T>
class segmentree
{
	int *A,size;
	public:
		segmenttree(int n)
		{
			int size=ceil(log(2*n))+1;
			size=2*(int)pow(2,size);
			A = new int[size];
			memset(a,-1,sizeof(a));
		}
		
		void initialize(int node,int start,int end,T *array)
		{
			if(start == end)
			{
				A[node]==start;
			}
			else
			{
				int mid=(start+end)/2;
				initialize(2*node,start,mid,array);
				initialize(2*node+1,mid+1,end,array);
				if(array[A[2*node]]<array[A[2*node+1]])
				A[node]=A[2*node];
				else
				A[node]=A[2*node+1];
			}
		}
		int query(int node,int start,int end,int b,int e,T *array)
		{
			int id1,id2;
			if((b>end)||(e<start))
			return -1;
			if((b<=start)&&(e>=end))
			return A[node];
			if((b==end)||(e==start))
			return A[node];
			int mid=(int)((start+end)/2);
			id1=query(2*node,start,mid,b,e,array);
			id2=query(2*node+1,mid+1,end,b,e,array);
			if(id1==-1)
			return id2;
			if(id2==-1)
			return id1;
			if(array[A[id1]]<array[A[id2]])
			return id2
			else if(array[A[id1]]>=array[A[id2]])
			return id1;
		}
}
