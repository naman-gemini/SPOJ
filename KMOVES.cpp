#include<cstdio>
#define ll long long
using namespace std;

ll f(ll n)
{
    if (n%2 == 1) return 0;
    if (n == 0) return 1;
    if (n == 2) return 33;
    ll  ans= 0;
    ans+=n*(2*n+1)-(n)*(n+1)/2;
    ans*=2;
    ans-=2*n;
    ans+=(2*n+2*n+1)*(n+1);
    return ans;
}

int main()
{
    int t;
    ll n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",f(n));
    }
    return 0;
}
