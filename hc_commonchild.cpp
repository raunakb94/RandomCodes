#include<bits/stdc++.h>
using namespace std;
/*
OUDFRMYMAW
AWHYFCCMQX
2
WEWOUCUIDGCGTRMEZEPXZFEJWISRSBBSYXAYDFEJJDLEBVHHKS
FDAGCXGKCTKWNECHMRXZWMLRYUCOCZHJRRJBOAJOQJZZVUYXIC
15
*/
int lcs(string str1,string str2)
{
    int arr[str1.length()+1][str1.length()+1];
    for(int i=0;i<=str1.length();i++)
    {
        for(int j=0;j<=str2.length();j++)
        {
            if(i==0||j==0)
            arr[i][j]=0;
            else if(str1[i-1]==str2[j-1])
            arr[i][j]=arr[i-1][j-1]+1;
            else
            arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    }
    return arr[str1.length()][str1.length()];
}
int main()
{
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    cout<<lcs(str1,str2);
}
