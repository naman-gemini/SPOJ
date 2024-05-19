#include<cstdio>
#include<cstring>
#include<algorithm>
#define DEBUG(x) printf(#x"=%d\n",x)
using namespace std;
typedef long long ll;
int a[100005];
int b[2][100005];

bool bs(int size,int key)
{
    int low,high,mid;
    low=0;
    high=size-1;
    mid=0;
    while(b[0][mid]!=key && low<=high)
    {
        mid=(low+high)/2;
        if(b[0][mid]<key) low=mid+1;
        else high=mid-1;
    }
    if(b[0][mid]==key) return true;
    else return false;
}

int bv(int size,int key)
{
    int low,high,mid;
    low=0;
    high=size-1;
    mid=0;
    while(b[0][mid]!=key && low<=high)
    {
        mid=(low+high)/2;
        if(b[0][mid]<key) low=mid+1;
        else high=mid-1;
    }
    if(b[0][mid]==key) return b[1][mid];
}

int main()
{
    int t,x,n,curr,count,tcount;
    ll ans;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        tcount=0;
        ans=0;
        scanf("%d %d",&x,&n);
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0,j=0; i<n; j++)
        {
            count=0;
            curr=a[i];

            while(a[i]==curr)
            {
                i++;
                count++;
            }
            b[0][j]=curr;
            b[1][j]=count;
            tcount++;

        }

        for(int i=0; i<tcount; i++)
        {
            if(2*b[0][i]==x) ans+=((ll)(b[1][i])*(b[1][i]-1));
            else if(bs(tcount,x-b[0][i]))
            {
                ans+=(ll)(b[1][i])*bv(tcount,x-b[0][i]);
            }
        }
        printf("%d. %lld\n",cs,ans/2);
    }
    return 0;
}
