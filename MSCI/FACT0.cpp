#include<cstdio>
#include<cmath>
#include<cstdlib>
typedef long long ll;

ll modular(ll exp)
{
    ll result=1;
    ll base=2,mod=exp;
    while(exp>0)
    {
        if((exp&1)==1)
            result=(result*base)%mod;
        exp=exp>>1;
        base=(base*base)%mod;
    }
    return result;
}

bool prime(ll n)
{
    if(modular(n)==2) return true;
}

void primeFactor (long long int n)
{
    long long int i,j,k,x=0;

    if(n==1) printf("1^1 ");

    if(n%2==0)
    {
        while(n%2 == 0)
        {
            n=n/2;
            x++;
        }
        printf("2^%lld ",x);
    }

    x=0;
    for(i=3; i<=n; i+=2)
    {
        k=0;
        if(n%i==0)
        {
            if(prime(i))
            {
                while(n%i==0)
                {
                    n=n/i;
                    k++;
                }

                printf("%lld^%lld ",i,k);
            }
        }
    }
}

int main()
{
    long long n;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0) return 0;
        primeFactor(n);
        printf("\n");
    }
    return 0;
}

