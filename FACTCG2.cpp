#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
using namespace std;

bool prime[10000001];

void init()
{
    for(int i=0; i<=10000000; i++)
    {
        prime[i]=true;      //default prime
    }
}
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

void prime_array_cons()
{
    init();
    for(int i=4; i<=10000000; i++)
    {
        if(!Miller(i,1)) prime[i]=false;
    }
}


/*void prime_array_cons()
{
    init();
    for(int i=4; i<=10000000; i++)
    {
        if(i%2==0) prime[i]=false;
        int sq=ceil(sqrt(i));
        for(int j=3; j<=sq; j+=2)
        {
            if(i%j==0)
            {
                prime[i]=false;
                break;
            }
        }
    }
}*/

int main()
{
    int n;
    //prime_array_cons();
    //printf("%d %d %d",prime[9],prime[11],prime[16]);
    while(scanf("%d",&n))
    {
        //printf("%d\n",Miller(n,5));
        //continue;
        if(n==1)
        {
            printf("1\n");
            continue;
        }

        if(Miller(n,40))
        {
            printf("1 x %d\n",n);
            continue;
        }

        printf("1");

        while(n!=1)
        {
            int k = ceil(sqrt(n));
            //bool flag=false;
            for(int i=2; i<=k; i++)
            {
                if(Miller(i,40))
                {
                    if(n%i==0)
                    {
                        printf(" x %d",i);
                        n=n/i;
                        if(Miller(n,40))
                        {
                            printf(" x %d",n);
                            n=1;
                        }
                        //flag=true;
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
