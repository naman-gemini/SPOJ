#include<cstdio>
#include<cmath>
#include<set>
typedef long long LL;
#define m 31625

int main()
{
    LL a[m],c,b;
    int i=0;
    for(; i<m ; i++)
    a[i]=i*i;

    while(scanf("%lld",&c))
    {
        int r=0,w=0,k=c/2;
        for(i=0;i<m;i++)
        {
            if(a[i]>k) break;
            b=sqrt(c-a[i]);
            if(ceil(b)==floor(b) && a[i]+b*b==c)w++;
        }
        printf("%lld\n",w);
    }
    return 0;
}
