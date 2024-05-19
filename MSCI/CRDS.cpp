#include<cstdio>
#define MOD 1000007
using namespace std;

long long a[1000005];
void start()
{
    long long diff=5;
    a[1]=2;
    for(int i=2;i<=1000000;i++)
    {
        a[i]=(a[i-1]%MOD+diff%MOD)%MOD;
        diff=(diff%MOD+3)%MOD;
    }
}

int main()
{
    int t,n;
    start();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
