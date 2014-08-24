#include<bits/stdc++.h>
using namespace std;
void fn(int *a, int *b)
{int *t;
t=a;
a=b;
b=t;
}

main()
{unsigned int num;
    int i;
    scanf("%u", &num);
    for(i=0; i<16; i++)
    {
        printf("%d", (num<<i & 1<<15)?1:0);
    }
    return 0;
}
