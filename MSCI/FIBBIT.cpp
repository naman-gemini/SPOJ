#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

int arr[7]= {0,1,2,3,5,8,13};

ll sum_bin(ll x)
{
    ll sum=0;
    while(x)
    {
        sum+=x%2;
        x/=2;
    }
    return sum;
}

int main()
{
    while(true)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        ll count=0;
        for(ll i=a; i<=b; i++)
        {
            ll x=sum_bin(i);
            for(int j=0; j<7; j++)
            {
                if(x==arr[j]) count++;
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}
