#include<cstdio>
#include<algorithm>
using namespace std;

int dp[105][505];

int main()
{
    int w,t;
    int cost,fun,min_cost;

    while(1)
    {
        scanf("%d %d",&w,&t);
        if(w==0 && t==0) break;

        for(int i=1; i<=t; i++)
        {
            scanf("%d %d",&cost,&fun);
            for(int j=1; j<=w; j++)
            {
                if(cost>j)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-cost]+fun);
                }
            }

        }

        min_cost=0;
        while(dp[t][min_cost]!=dp[t][w])
        min_cost++;

        printf("%d %d\n",min_cost,dp[t][w]);
    }
    return 0;
}
