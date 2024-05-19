#include<cstdio>
#include<cmath>
#include<cstdlib>

/*int isPrime (long long int n)
{
    long long int i;
    if(n==2 || n==3) return 1;
    if(n%2==0 || n%3==0) return 0;              //returns 1 for prime

    if(n%6==1 || n%6==5)
    {
        long long int p=(long long int)(sqrt(n));
        for(i=3; i<=p; i+=2)
        {
            if(n%i==0)
                return 0;
        }
    }
    return 1;
}*/

int modulo(int a,int b,int c)
{
    // res is kept as long long because intermediate results might overflow in "int"
    long long res = 1;
    for(int i=0; i<b; i++)
    {
        res *= a;
        res %= c; // this step is valid because (a*b)%c = ((a%c)*(b%c))%c
    }
    return res%c;
}

long long mulmod(long long a,long long b,long long c)
{
    long long x = 0,y=a%c;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

bool Miller(long long p,int iteration)
{
    if(p<2)
    {
        return false;
    }
    if(p!=2 && p%2==0)
    {
        return false;
    }
    long long s=p-1;
    while(s%2==0)
    {
        s/=2;
    }
    for(int i=0; i<iteration; i++)
    {
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1)
        {
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0)
        {
            return false;
        }
    }
    return true;
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
            if(Miller(i,1))
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
