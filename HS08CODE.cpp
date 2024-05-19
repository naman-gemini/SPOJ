#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

ll mould (ll a,ll b,ll c,ll d,ll x)
{

    return ((a*x+b)*x+c)*x+d;
}

ll bsearch(ll a,ll b,ll c,ll d,ll low,ll hi)
{
    ll mid ;
    while(low<hi)
    {
        mid=(low+hi)/2;
        ll f = mould (a,b,c,d,low);
        ll s = mould (a,b,c,d,mid);
        if((f>0 &&s >0)||(f<0 && s<0)) low=mid+1;
        else hi=mid;
    }
    return low;
}

void solve ( ll n , ll phi , ll sigma )
{
    ll a=2,b=2*n-phi-sigma,c=sigma-phi-2,d=-2*n;
    ll dis=(ll)sqrtl((4*b*b-12*a*c)*1.0);
    ll low=(ll)ceill((-2*b-dis)/(6.0*a));
    ll high=(ll)floor((-2*b+dis)/(6.0*a));
    ll r=bsearch(a,b,c,d,low,high);
    ll d1=-(b+r*a);
    ll d2=(ll)sqrtl(b*b-4*a*c-2*a*b*r-3*a*a*r*r);
    ll r1=(ll)((d1-d2)/(2*a));
    ll r2=(ll)((d1+d2)/(2*a));
    printf("%lld %lld %lld\n",r1,r,r2);
}

int main()
{
    int t;
    ll n,phi,sigma ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n,&phi,&sigma);
        solve (n,phi,sigma);
    }
}
