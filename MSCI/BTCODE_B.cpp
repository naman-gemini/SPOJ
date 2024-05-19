#include <cstdio>
#include<cmath>
using namespace std;

#define s(T) scanf("%d", &T)
#define fill(a, val) memset(a, val, sizeof(a))
#define sl(T) scanf("%lld", &T)

int n;
int a[50];
int k[50];
int y[50];
int x;

void input()
{
    s(n);
    s(x);
    for(int i=0; i<n; i++)
        s(k[i]);
    for(int i=0; i<n; i++)
        s(a[i]);
    for(int i=0; i<n; i++)
        s(y[i]);
}

void solve()
{
    double ans=1.0;
    double sum=0.0;
    for(int i=0; i<n; i++)
    {
        double term=1.0;
        term*=y[i];
        term*=a[i];
        term/=k[i];
        double power=k[i];
        power/=y[i];
        ans*=pow(term,power);
        sum+=(double)k[i]/y[i];
    }
    ans*=x;
    ans = pow(ans,1.0/sum);
    ans *= sum;
    printf("%d\n",(int)(ans+0.5));
}

int main()
{
    int T;
    s(T);
    while(T--)
    {
        input();
        solve();
    }
}
