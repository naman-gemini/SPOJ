#include<cstdio>
#include<algorithm>
#include<cmath>
#include<ctime>
#define MAX 100005
#define DEBUG(x) printf(#x"=%d\n",x)
using namespace std;

int a[MAX],b[MAX],c[MAX],d[MAX];

int main()
{
    int t,n,m,median,low,flag,x;
    scanf("%d",&t);
    while(t--)
    {
        srand(time(NULL));
        printf("\n------------------------------------------------\n");
        n=50000;
        //scanf("%d",&n);
        //for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        for(int i=1; i<=n; i++)
        {
            //scanf("%d",&b[i]);
            //c[i]=a[i]-b[i];
            c[i]=rand()%100000;
        }
        sort(c+1,c+n+1);

        if(n%2==1) median=c[(n+1)/2];
        else median=c[n/2];

        DEBUG(median);

        //scanf("%d",&m);
        m=50000;
        low=1000000000;
        for(int i=1; i<=m; i++)
        {
            //scanf("%d",&d[i]);
            d[i]=(rand()%(2*median));
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
        //DEBUG(flag);
        printf("My solution:%d at %d\n",d[flag],flag);

        //brute force solution starts here

        int brute_low=1000000000;
        int sum;
        for(int i=m; i>=1; i--)
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

        printf("Brute force solution:%d at %d\n",d[flag],flag);
    }
    return 0;
}
