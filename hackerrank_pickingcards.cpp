/*

    https://www.hackerrank.com/challenges/picking-cards
    Input Format
The first line contains the number of test cases T. T test cases follow. Each case contains an integer N on the first line, followed by integers c1,..ci,...,cN on the second line.

Output Format
Output T lines one corresponding to each test case containing the required answer for the corresponding test case. As the answers can be very big, output them modulo 1000000007.

*/
#include<bits/stdc++.h>
int fact(int n)
{
    if(n==1 || n==0)
    return 1;
    else return n*fact(n-1);
}
using namespace std;
int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N;
        cin>>N;
        vector<int>arr;
        while(N--)
        {
        int data;
        cin>>data;
        arr.push_back(data);
        }
    sort(arr.begin(),arr.end());
    int buffer = 0;
    int count =1;
    int selected = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(selected + buffer >= arr[i])
        {
            int q = (arr[i]-selected);
            count = count*fact(q);
            buffer = buffer-q;
            selected+=q;
        }
        if(selected>=arr[i])
        buffer++;
    }
    count = count*fact(buffer);
    cout<<count<<endl;

    }

}
