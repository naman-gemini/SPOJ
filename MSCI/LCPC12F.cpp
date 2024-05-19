#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[100005];

ll comb(int n)
{
    return ((ll)n*(n-1))/2;
}
int main()
{
    int t,x,n,diff;
    ll ans,ans2;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        ans=0;
        ans2=0;
        scanf("%d %d",&x,&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(binary_search(a,a+n,x-a[i]))
            {
                if(2*a[i]!=x) ans++;
                else
                {
                    diff=upper_bound(a,a+n,a[i])-1-lower_bound(a,a+n,a[i]);
                    if(diff!=0)
                    {
                        printf("diff=%d\n",diff);
                        ans2+=comb(diff+1);
                        i=upper_bound(a,a+n,a[i])-a;
                    }
                }
            }
        }
        printf("%d. %d\n",cs,ans+ans2);
    }
    return 0;
}
