#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> v;

bool isprime(long long n)
{
    if(n%2==0) return false;

    if(n%6==1 || n%6==5)
    {
        long long s=(long long)(sqrtl(n));
        for(long long i=3; i<=s; i+=2)
        {
            if(n%i==0)
                return false;
        }
    }
    else
        return false;

    return true;
}

int main()
{
    long long int i=5;
    v.push_back(2);
    v.push_back(3);
    while(v.size()<=5000000)
    {
        if(isprime(i)) v.push_back(i);
        i++;
    }
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",v[n-1]);
    }
    return 0;
}
