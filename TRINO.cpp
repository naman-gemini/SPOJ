#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    long long m,n,p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&m,&n);
        p=(m/2)*n;
        q=(n/2)*m;
        (p<q)? printf("%lld\n",p) : printf("%lld\n",q);
    }
    return 0;
}

