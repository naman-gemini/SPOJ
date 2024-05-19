#include<cstdio>
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll modular_pow(ll base,ll exponent,ll mod)
{
    ll result=1;
    while(exponent>0)
    {
        if((exponent&1)==1)
        {
            result=(result*base)%mod;
        }
        exponent = exponent >> 1;   //divide by 2
        base=(base*base)%mod;
    }
    return result;
}

int main()
{
    int t,n,val;
    ll ans,sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&val);
            sum+=val;
        }
        sum=sum%MOD;

        ans=modular_pow(2,n-1,MOD)%MOD;
        printf("%lld\n",(ans*sum)%MOD);
    }
    return 0;
}
