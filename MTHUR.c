#include<stdio.h>
#include<stdlib.h>
#define MAX 100005
long long int a[MAX],b[MAX],c[MAX],d[MAX];

int main()
{
    int t,n;
    long long int x,sum=0,ls=0,lsum=0,j,i,k,cs;
    scanf("%d",&t);
    for(cs=0; cs<t; cs++)
    {
        lsum=0;
        ls=0;
        scanf("%d",&n);

        for(i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0; i<n; i++)
        {
            scanf("%lld",&b[i]);
        }
        scanf("%lld",&x);
        for(i=0; i<x; i++)
        {
            scanf("%lld",&c[i]);
        }
        for(i=0; i<n; i++)
        {
            d[i]=a[i]-b[i];
        }
        for(k=0; k<x; k++)
        {
            sum=0;
            for(j=0; j<n; j++)
            {
                sum=sum+abs(d[j]-c[k]);
            }
            if((sum<lsum) || k==0)
            {
                lsum=sum;
                ls=c[k];
            }
            else if(sum==lsum)
            {
                if(c[k]<ls)
                    ls=c[k];
            }
        }
        printf("%lld\n",ls);
    }
    return 0;
}
