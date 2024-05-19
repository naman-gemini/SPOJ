#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;

int main()
{
    ll ans=0,n,k,mid=0;
    scanf("%lld %lld",&n,&k);
    if(k==1)
    {
        printf("%lld\n",n*n);
        return 0;
    }
    if(k>=n) printf("%lld\n",2*n-1);
    else
    {
        ans+=2*k;
        mid+=(n+k)*(n-k-1);
        mid+=n;
        ans+=ceil((double)mid/k);
        printf("%lld\n",ans);
    }
    return 0;
}

