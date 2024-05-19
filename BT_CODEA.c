#include<stdio.h>

long long gcd(long long a, long long b)
{
    long long t;
    while(b)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int main()
{
    int t;
    long long a,b,c,d,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a<0) a=-a;
        if(b<0) b=-b;
        if(c<0) c=-c;
        if(d<0) d=-d;

        x=gcd(a,b);
        y=gcd(c,d);

        if(x==0)
        {
            if(y>0) printf("NO\n");
            else printf("YES\n");
            continue;
        }

        if(y==0)
        {
            printf("NO\n");
            continue;
        }

        if(y%x==0)
        {
            long long z=y/x;
            if((z&-z)==z) printf("YES\n");
            else printf("NO\n");
        }

        else printf("NO\n");

    }
    return 0;
}
