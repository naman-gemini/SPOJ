#include<stdio.h>
#include<math.h>
#define mod 1000000007

double phi = (1+sqrt(5))/2;
double x = sqrt(5);

long long int sum(long long int n)
{
    return (pow(phi,n+2) - pow(1-phi,n+2))/x - 1;
}

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        printf("%lld\n",(sum(m)%mod+(-sum(n-1))%mod)%mod);

    }
    return 0;
}
