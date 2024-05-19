#include<cstdio>
using namespace std;
typedef long long ll;

int main()
{
    ll ans=0,n,k,available=0;
    scanf("%lld %lld",&n,&k);
    if(k>=n) printf("%lld\n",2*n-1);
    else
    {
        for(int i=1;i<=n;i++)
        {
            available+=i;
            while(available>0)
            {
                available-=k;
                ans++;
            }
            available=0;
        }

        for(int i=n-1;i>=1;i--)
        {
            available+=i;
            while(available>0)
            {
                available-=k;
                ans++;
            }
            available=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
