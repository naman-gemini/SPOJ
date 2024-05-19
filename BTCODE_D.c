#include<stdio.h>
#define MIN(a,b) a<b?a:b
int main()
{
    int a[110][110],b[110][110],i,j,m,n,t;
    long long int sum,max,profit,c[110][110];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                scanf("%d",&b[i][j]);
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                scanf("%lld",&c[i][j]);
        sum=0;
        for(i=0; i<m; i++)
        {
            max=0ULL;
            for(j=0; j<n; j++)
            {
                profit=MIN(a[i][j],b[i][j]);
                profit*=c[i][j];
                if(profit>max) max=profit;
            }
            sum+=max;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
