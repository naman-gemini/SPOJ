#include<cstdio>
#include<ctime>
#define MOD 4000000007
#define K 1000000002
using namespace std;
typedef unsigned long long ll;

ll modular(ll base, ll exp)
{
    ll result = 1;
    while(exp>0)
    {
        if(exp%2==1)
        {
            result=((result)*(base))%MOD;
        }
        exp=exp>>1;
        base=((base)*(base))%MOD;
    }
    if(result>2000000003) result=MOD-result;
    return result;
}

int main()
{
    long long int a;
    scanf("%lld",&a);
    ll x;
    x=modular(a,K);
    //printf("x=%lld\n",x);
    time_t t=x;
    printf("%s\n",asctime(gmtime(&t)));
    return 0;
}
