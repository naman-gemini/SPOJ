#include<cstdio>
using namespace std ;

long long solve(int a)
{
    if(a == 0) return 0 ;
    if(a % 2 == 0) return solve(a - 1) + __builtin_popcount(a) ;
    return ((long long)a + 1) / 2 + 2 * solve(a / 2);
}

long long solve(int a,int b)
{
    if(a >= 0)
    {
        long long ret = solve(b);
        if(a > 0) ret -= solve(a - 1) ;
        return ret ;
    }
    long long ret = (32 * -(long long)a) - solve(~a);
    if(b > 0) ret += solve(b) ;
    else if(b < -1)
    {
        b++ ;
        ret -= (32 * -(long long)b) - solve(~b);
    }
    return ret ;
}

int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        long long ret = solve(a,b) ;
        printf("%lld\n",ret);
    }
    return 0 ;
}
