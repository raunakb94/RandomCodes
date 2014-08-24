    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int T;
        cin>>T;
        int count = 0;
        while(T--)
        {
            string str;

            cin>>str;
            char arr[str.length()];
            int i=1;
            arr[0]=str[0];
            int j = 1;
            while(j<str.length())
            {
                if(i==0)
                {arr[i]=str[j];
                i++;
                }
                else if(arr[i-1]==str[j])
                i--;
                else
                {arr[i]=str[j];
                i++;
                }
                j++;
            }
            if(i==0)
            count++;
                }
        cout<<count;
    }
