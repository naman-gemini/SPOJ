#include<stdio.h>
#define max 1000000000
#define mod 1000000007

long long a[max/10+1];

void precal()
{
    int i;
    a[0]=0;
    a[1]=1;
    a[2]=1;
    for(i=3;i<=max/10;i++)
    {
        a[i]=a[i-1]%mod+a[i-2]%mod;
        a[i]%=mod;
    }
}

int main()
{
    int t,n,m;
    scanf("%d",&t);
    precal();
    while(t--)
    {
        long long sum=0;
        scanf("%d %d",&n,&m);
        while(n<=m)
        {
            sum+=(a[n]%mod);
            n++;
        }
        sum=sum%mod;
        printf("%lld\n",sum);
    }
    return 0;
}
