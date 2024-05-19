#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t,m,n,A,B,r[30][30],o1,o2;
bool dp[30][30][1300];

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d%d%d",&m,&n,&A,&B);
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                scanf("%d",&r[i][j]);
            }
        }
        memset(dp,false,sizeof(dp));
        for (int j=0; j<n; j++)
        {
            dp[0][j][r[0][j]+650]=true;
        }
        for (int i=0; i+1<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                for (int k=20; k<=1275; k++)
                {
                    if (dp[i][j][k])
                    {
                        if (j!=0)
                        {
                            dp[i+1][j-1][k+r[i+1][j-1]]=true;
                        }
                        dp[i+1][j][k+r[i+1][j]]=true;
                        if (j+1!=n)
                        {
                            dp[i+1][j+1][k+r[i+1][j+1]]=true;
                        }
                    }
                }
            }
        }
        o1=10000;
        o2=-10000;
        for (int j=0; j<n; j++)
        {
            for (int k=20; k<=1275; k++)
            {
                if ((A<=k-650)&&(k-650<=B)&&(dp[m-1][j][k]))
                {
                    o1=min(o1,k-650);
                    o2=max(o2,k-650);
                }
            }
        }
        if (o1==10000)
        {
            printf("NO NO\n");
        }
        else
        {
            printf("%d %d\n",o1,o2);
        }
    }
    return 0;
}
