#include<stdio.h>
#define C 10000007

long long int function(long long int a,long long int b)
{
        long long int result;
        result=1;
        while(b>0)
        {
                if((b & 1)==1)
                result = (result * a) % C;

                b=b>>1;
                a=(a*a)%C;
        }
        return result;
}

int main()
{
    int t;
    long long int n,k;
    while(1)
    {
        scanf("%lld %lld",&n,&k);
        if(n==0 && k==0) return 0;

        printf("%lld\n",(function(n,k) + function(n,n) + function(n-1,k) + function(n-1,k) + function(n-1,n-1) + function(n-1,n-1))%C);
    }
    return 0;
}
