#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

long long stirling( long long k)
{
    double ret,n=k*1.0;
    ret=n*log(n)-n+0.5* log(2*M_PI*n);
    return (( long long )(ret* log10 (M_E))+1LL);
}
int main()
{
    long long t,n;
    for( scanf( "%lld" ,&t); t>0; t--)
    {
        scanf ("%lld" ,&n);
        n++;
        long long lo=1,hi=2147483648,mid;
        while (lo<hi)
        {
            mid=(lo+hi)/2;
            if (stirling(mid)<n) lo=mid+1;
            else hi=mid;
        }
        mid=(lo+hi)/2;
        printf("%lld\n" ,mid-1);
    }
    return 0;

}
