#include <stdio.h>
#define ll long long

ll sol (ll a)
{
    ll res = a, add = 1;
    while (a)
    {
        a /= 2;
        res += add*a;
        add *= 2;
    }
    return res;
}

int main ()
{
    ll a, b;
    while (scanf("%lld %lld", &a, &b) == 2)
    printf ("%lld\n", sol(b)-sol(a-1));
    return 0;
}
