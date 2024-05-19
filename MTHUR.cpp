#include<cstdio>
#include<algorithm>
#include<cmath>
#include<ctime>
#define MAX 100005
#define DEBUG(x) printf(#x"=%d\n",x)
using namespace std;

int a[MAX],b[MAX],c[MAX];


int partition(int p,int r)
{
    int x,i;
    x=c[r];
    i=p-1;
    for (int j=p;j<r;j++)
    {
        if(c[j]<x)
        {
            i++;
            swap(c[i],c[j]);
        }
    }
    swap(c[i+1],c[r]);
    return i+1;
}
int random_partition(int p,int r)
{
    int i=rand()%(p+1)+(r-p);
    swap(c[r],c[i]);
    return partition(p,r);
}

int select(int p,int r,int i)
{
    if(p==r) return c[p];
    int q,k;
    q=random_partition(p,r);
    k=q-p+1;
    if(i==k) return c[q];
    else if (i<k) return select(p,q-1,i);
    else return select(q+1,r,i-k);
}

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
        //sort(c+1,c+n+1);

        //if(n%2==1) median=c[(n+1)/2];
        //else median=c[n/2];

        if(n%2==1) median=select(1,n,(n+1)/2);
        else median=select(1,n,n/2);

        //DEBUG(median);

        scanf("%d",&m);
        low=1000000000;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&a[i]);
        }
        //sort(d+1,d+1+m);

        for(int i=1; i<=m; i++)
        {
            x=(a[i]-median);
            if(x<0) x=-x;
            if(x<low)
            {
                low=x;
                flag=i;
                //DEBUG(low);
            }
            else if(x==low)
            {
                if(a[i]<a[flag])
                    flag=i;
            }
        }
        int gt=MAX*10;
        int lt=-1;
        median=a[flag];
        bool nogt=true;
        bool nolt=true;

        for(int i=1;i<=m;i++)
        {
            if(a[i]<median)
            {
                nolt=false;
                break;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(a[i]>median)
            {
                nogt=false;
                break;
            }
        }

        for(int i=1;i<=m;i++)
        {
            if(a[i]>median && a[i]<gt)
            gt=a[i];
            if(a[i]<median && a[i]>lt)
            lt=a[i];
        }
        //DEBUG(gt);
        //DEBUG(lt);

        int sum;
        int brute_low=1000000000;
        a[1]=lt;
        a[2]=median;
        a[3]=gt;

        int start=1,stop=3;

        if(nogt) stop--;
        if(nolt) start++;

        for(int i=stop;i>=start;i--)
        {
            sum=0;
            for(int j=1; j<=n; j++)
            {
                sum+=abs(c[j]-a[i]);
            }
            if(sum<=brute_low)
            {
                brute_low=sum;
                flag=i;
            }
        }

        //DEBUG(flag);
        printf("%d\n",a[flag]);
    }
    return 0;
}
