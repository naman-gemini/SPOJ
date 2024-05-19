#include<cstdio>
#define MAX 500000
using namespace std;
typedef long long ll;

ll a[MAX+1];
bool check[10*MAX];

void solve()
{
    ll temp;
    a[0]=0;
    for(int i=0;i<2*MAX;i++) check[i]=0;
    for(int i=1;i<=MAX;i++)
    {
        temp=a[i-1];
        if(temp-i > 0 && check[temp-i]==0)
        {
            a[i]=temp-i;
            //printf("%lld\t",a[i]);
            check[temp-i]=1;
        }
        else
        {
            a[i]=temp+i;
            //printf("%lld\t",a[i]);
            check[temp+i]=1;
        }
    }
}

int main()
{
    int t;
    solve();
    while(scanf("%d",&t) && t!=-1)
    {
       printf("%lld\n",a[t]);
    }
    return 0;
}
