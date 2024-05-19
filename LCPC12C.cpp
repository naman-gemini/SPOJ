#include<cstdio>
#include<cstdlib>
#include<stack>
typedef long long ll;
using namespace std;

stack<ll> s_min;
stack<ll> s_gen;
static int j;
static int S;

ll makeR(ll *h,int m)
{
    ll R;
    {
        R=h[j];
        S=(j+1)%m;
        h[j]=((h[j]^h[S])+13)% 835454957;
        j=S;
    }
    return R;
}

int main()
{
    int t,cs=1,n,m,x;
    ll h[55],R,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        j=0;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
            scanf("%lld",&h[i]);

        for(int i=0; i<n; i++)
        {
            R=makeR(h,m);
            x=R%3;

            if(x==0)
            {
                if(!s_min.empty())
                ans+=s_min.top();
            }
            else if(x==1)
            {
                if(!s_gen.empty())
                {
                    if(!s_min.empty() && s_gen.top()==s_min.top()) s_min.pop(); //means recent item was min
                    s_gen.pop();
                }

            }
            else
            {
                s_gen.push(R);
                if(s_min.empty()) s_min.push(R);
                else if(R<=s_min.top()) s_min.push(R);
            }
        }
        printf("%d. %lld\n",cs++,ans);
        while(!s_gen.empty()) s_gen.pop();
        while(!s_min.empty()) s_min.pop();
    }
    return 0;
}
