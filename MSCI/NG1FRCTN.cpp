#include<cstdio>
#include<algorithm>
#define ll long long

ll gcd(ll a, ll b)
{
    int t;
	while(b)
	{
	    t=b;
	    b=a%b;
	    a=t;
	}
}

void solve(ll n, ll &l, ll &h)
{
    //terminating condition
	if(n==1)
	{
	    l=1;
	    h=1;
	}

	else
	{
		solve(n/2,l,h);
		if(n%2==1) l+=h;
		else h+=l;
	}
}

int main()
{
	ll a, b, l1, l2, h1, h2, g;
	while(scanf("%lld%lld", &a, &b)==2 && a && b)
	{
		solve(a,l1,h1);
		solve(b,l2,h2);
		g = gcd(l1,h2);
		printf("%lld/%lld\n", l1/g, h2/g);
	}
	return 0;
}

