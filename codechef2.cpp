/*
Little Elephant likes lemonade.
When Little Elephant visits any room, he finds the bottle of the lemonade in that room that contains the greatest number of litres of lemonade and drinks it all.
There are n rooms (numbered from 0 to n-1), each contains Ci bottles. Each bottle has a volume (in litres). The first room visited by Little Elephant was P0-th, the second - P1-th, ..., the m-th - Pm-1-th room. Note that Little Elephant may visit a room more than once.
Find for Little Elephant the total volume of lemonade he has drunk.
Input

First line of the input contains single integer T - the number of test cases. T test cases follow. First line of each test case contains 
pair of integers n and m. Second line contains m integers separated by a single space - array P. Next n lines describe bottles in each 
room in such format: Ci V0 V1 ... VCi-1, where V is the list of volumes (in liters) of all bottles in i-th room.
Output

In T lines print T integers - the answers for the corresponding test cases.
Constraints

1 <= T <= 10
1 <= n, Ci <= 100
1 <= m <= 10^4
0 <= Pi < n
1 <= Vi <= 10^5
Example

Input:
2
3 3
0 2 1
3 1 2 3
1 7
2 4 7
4 7
0 1 3 0 1 0 0
1 7
3 9 4 5
7 1 2 3 4 5 6 7
1 1

Output:
17
22
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int no_test;
	cin>>no_test;
	while(no_test>0)
	{
		long int n,m;
		cin>>n>>m;
		int *arr1 =new int[m+1];
		int i=0;
		while(i<m)
		{
			cin>>arr1[i++];
		}
		vector<vector<int>> vec;
		i=0;
		while(i<n)
		{
			vector<int> temp;
			int num;
			cin>>num;
			int p=0;
			while(p<num)
			{
				int num1;
				cin>>num1;
				temp.push_back(num1);
				
			}
			sort(temp.begin(),temp.end());
			vec.push_back(temp);
		}
		 		
 	}
}
