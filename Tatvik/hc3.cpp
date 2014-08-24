#include<bits/stdc++.h>
using namespace std;
vector<int> primeFactors(int n)
{
    vector<int>arr;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        arr.push_back(2);
        n = n/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            arr.push_back(i);
            n = n/i;
        }
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        arr.push_back(n);
        return arr;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    int arr[4];
    int i=0;
    while(i<4)
    {
        cin>>arr[i++];

    }
    vector<int>arr1 = primeFactors(arr[0]);
    map<int,int> set1;
    for(int i=0;i<arr1.size();i++)
    {
        if(set1.find(arr1[i])!=set1.end())
        set1[arr1[i]]=1;
        else
        set1[arr1[i]]++;

          //      cout<<set1[arr1[i]]<<"--1"<<arr1[i]<<endl;

    }
    for(int i=0;i<set1.size();i++)
    {
        set1[i] *= arr[1];
        //cout<<set1[i];
    }


    vector<int>arr2 = primeFactors(arr[2]);
    map<int,int> set2;
    for(int i=0;i<arr2.size();i++)
    {
        if(set1.find(arr2[i])!=set2.end())
        set2[arr2[i]]=1;
        else
        set2[arr2[i]]++;

        //cout<<set2[arr2[i]]<<"--2"<<arr2[i]<<endl;
    }
    for(int i=0;i<set1.size();i++)
    {
        set2[i] *= arr[3];
        //cout<<set2[i];
    }
    int t = 0;
    for(std::map<int,int>::iterator it = set2.begin();it!=set2.end()&&t==0;it++)
    {
        int q = it->first;
        int r = it->second;
        //cout<<endl<<q<<"Second"<<r<<"valut"<<set1[q]<<"qq"<<r;
        if(set1[q]<r)
       {
        t = 1;
        break;
        }
    }
    if(t==1)
    cout<<"Not divisible"<<endl;
    else
    cout<<"Divisible"<<endl;
    }

}
