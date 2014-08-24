/*
	Input

First line of input file contains two integers N (1<=N<=105) and K (1<=K<=N),
followed by a line containing N integers. The ith integer denotes f(i)-the cooking time of
meal number i (1<=f(i)<=109)
Output

Print minimum number of assistans which can cook all the meals in one line.
Example

Input:
5 3
40 30 40 30 40

Output:
3
*/

#include<bits/stdc++.h>
using namespace std;
class node{
	public :int value;
	int index;
};
bool compare(node A,node B)
{
	if(A.value<B.value)
	return true;
	else
	return false;
}
int main()
{
	int T;
	int size;
	cin>>T;
	cin>>size;
	node nodes[T];
	int min = INT_MAX;
	int minInd = INT_MAX;
	int i = 0;
	while(i<T)
	{
		int data;
		cin>>data;
		nodes[i].value = data;
		nodes[i].index = i;
		i++;
	}
	int chefs=0;
	sort(nodes,nodes+T,compare);
	/*for(int i = 0;i<T;i++)
	{
		cout<<nodes[i].value<<"->>"<<nodes[i].index<<endl;
	}*/
	for(int i = 0;i<T;)
	{
	chefs++;	
	int cur_val = nodes[i].value;
	int cur_index = nodes[i].index;
	int j = i+1;
	while(j<T && nodes[j].value == cur_val && nodes[j].index<cur_index + size)
	j++;
	
	i = j;
	}
	cout<<chefs;
}

