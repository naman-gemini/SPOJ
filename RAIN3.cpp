#include<iostream>
#include<cstdio>
using namespace std;


int s[2000000],t[2000000],a[2000000];


int main()
{
    int test,n,k;
    scanf("%d",&test);

    while(test--)
    {
        int n,m;
        scanf("%d %d",&s[0],&t[0]);
        scanf("%d %d",&n,&m);

        long long sum = 0;
        int L = 1;
        int res= n;
        for(int i=1; i<n; i++)
        {
            s[i] = (78901 + 31LL*s[i-1]) % 699037;
            t[i] = (23456 + 64LL*t[i-1]) % 2097151;
            a[i] = (s[i] % 100 + 1) * (t[i] % 100 + 1);
            sum += a[i];
            while(sum > m)
            {
                sum -= a[L++];
                if(res > (i-L+1))
                res = i-L+1;

            }

        }
        if(res > (n-L+1)) res = n-L+1;

        cout<<res<<endl;

    }

    return 0;
}

