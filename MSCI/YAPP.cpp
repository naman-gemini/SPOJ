#include<cstdio>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll solve(ll n)
{
    ll r=1,mult=2;
    while(n)
    {
        if(n & 1) r = (r * mult) % MOD;
        mult = (mult * mult) % MOD;
        n /= 2;
    }
    return r;
}

int main()
{
    ll t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        printf("%lld\n",solve(n-1));
    }
    return 0;
}
