#include<cstdio>
#include<cmath>
#include<cstring>
#define DEBUG(x) printf(#x"=%d\n",x)
#define MAX 100000
using namespace std;
typedef long long ll;


bool prime[MAX+1];
int count[MAX+1];

void init()
{
    for(int i=1; i*i<=MAX; i++)
        if(i%2==0) prime[i]=false;
        else prime[i]=true;
}

void precal()
{
    for(int i=3; i*i<=MAX; i+=2)
    {
        if(prime[i])
        for(int j=i*i; j<=MAX; j+=i)
        {
            prime[j]=false;
        }
    }
}

ll fx(int a,int b)
{
    ll res=0;
    for(int i=0;i<=b;i++) res+=pow(a,i);
    //DEBUG(res);
    return res;
}

ll solve(int k)
{
    memset(count,0,MAX);
    ll sum=1;
    int x=k;
    while(x%2==0)
    {
        count[2]++;
        x/=2;
    }
    //DEBUG(count[2]);
    for(int i=3;i<=k/2;i+=2)
    {
        //i is a prime factor
        if(prime[i] && x%i==0)
        {
            //printf("i=%d\n",i);
            while(x%i==0)
            {   count[i]++;
                x/=i;
            }
            //DEBUG(count[i]);
        }
    }

    for(int i=2;i<=k/2;i++)
    {
        if(count[i]!=0) sum*=fx(i,count[i]);
    }
    //printf("sum=%lld\n",sum);
    if(sum == 1) return 1;
    else return sum-1-k;
}

int main()
{
    int t,K,I,F;
    int ans1,ans2;
    ll ans3;
    init();
    precal();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&K,&I,&F);
        ans1=(int)(ceil((double)(K)/I));
        ans2=(int)(ceil((double)(K)/(K/F)));
        ans3=(ll)(ceil((double)(K)/solve(K)));

        printf("%d %d %lld\n",ans1,ans2,ans3);
    }
    return 0;
}

