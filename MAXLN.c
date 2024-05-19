#include<stdio.h>

int main()
{
    int t;
    long long r;
    int x=1;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%lld",&r);
        printf("Case %d: %.2f\n",x++,4*r*r+0.25);
    }
    return 0;
}
