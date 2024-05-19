#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAX 100005
#define DEBUG(x) printf(#x"=%d\n",x)
using namespace std;
typedef long long ll;

int a[MAX],b[MAX],c[MAX],d[MAX];

int main()
{
    int t,n,m,median,low,flag,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&b[i]);
            c[i]=a[i]-b[i];
        }
        sort(c+1,c+n+1);

        if(n%2==1) median=c[(n+1)/2];
        else median=c[n/2];

        //DEBUG(median);

        scanf("%d",&m);
        low=1000000000;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&d[i]);
        }
        sort(d+1,d+1+m);

        for(int i=1; i<=m; i++)
        {
            x=(d[i]-median);
            if(x<0) x=-x;
            if(x<low)
            {
                low=x;
                flag=i;
                //DEBUG(low);
            }
            else if(x==low)
            {
                if(d[i]<d[flag])
                    flag=i;
            }
        }

        int sum;
        int brute_low=1000000000;


        for(int i=min(flag+1000,m); i>=max(flag-1000,0); i--)
        {
            sum=0;
            for(int j=1; j<=n; j++)
            {
                sum+=abs(c[j]-d[i]);
            }
            if(sum<=brute_low)
            {
                brute_low=sum;
                flag=i;
            }
        }
        //DEBUG(flag);
        printf("%d\n",d[flag]);
    }
    return 0;
}
