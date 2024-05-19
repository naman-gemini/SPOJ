#include<cstdio>
#include<cstdlib>
#include<set>
typedef long long ll;
using namespace std;

multiset<ll> s;
multiset<ll>::iterator it;

static int j;
static int S;

ll makeR(ll *h,int m)
{
    ll R;
    //for(int i=0; i<n; i++)
    {
        R=h[j];
        S=(j+1)%m;
        h[j]=((h[j]^h[S])+13)% 835454957;
        j=S;
    }
    //printf("%lld\n",R);
    return R;
}

int main()
{
    int t,cs=1,n,m;
    ll h[55],R,ans,recent;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        j=0;
        recent=-1;
        scanf("%d %d",&n,&m);
        //R=(ll *)malloc(n*sizeof(ll));
        for(int i=0; i<m; i++)
            scanf("%lld",&h[i]);

        //for(int i=0;i<n;i++) printf("%d ",R[i]);
        //printf("\n");


        for(int i=0; i<n; i++)
        {
            R=makeR(h,m);
            switch(R%3)
            {
            case 0:
                if(s.size()>0)
                    ans+=*(s.begin());
                break;

            case 1:
                if(recent!=-1 && s.size()>0)
                {
                    it=s.lower_bound(recent);
                    s.erase(it);
                }
                break;

            case 2:
                s.insert(R);
                recent=R;
                break;

            }
        }

        printf("%d. %lld\n",cs++,ans);
        if(s.size()>0) s.clear();
    }
    return 0;
}
