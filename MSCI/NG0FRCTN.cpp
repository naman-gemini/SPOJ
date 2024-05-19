#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

#define MAX 10000000000

vector<ll> v;
vector<ll>::iterator it;

int find_level(ll n)
{
    ll i;
    for(i=2;; i+=i)
    {
        if(i>n) break;
    }
    return int(log2(i))-1;
}

int main()
{
    ll n,a,b;
    int k;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0) return 0;
        if(n==1) printf("1/1\n");
        else
        {
            v.clear();
            k=find_level(n);
            n-=pow(2,k);
            for(int i=k; i>=0; i--)
            {
                v.push_back(n);
                n=n/2;
            }
            reverse(v.begin(),v.end());
            a=1,b=1;
            for(it=v.begin()+1; it!=v.end(); it++)
            {
                if(*it == 2* (*(it-1))) b+=a;
                else
                    a+=b;
            }

            printf("%lld/%lld\n",a,b);
        }
    }
}
