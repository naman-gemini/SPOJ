#include<cstdio>
#include<algorithm>
using namespace std;

int inp[1000005][3];
int dp[1000005][3];
int main()
{
    int t;
    int case_=1;
    while(1)
    {
        scanf("%d",&t);
        if(t==0) break;
        for(int i=0; i<t; i++)
        {
            scanf("%d %d %d",&inp[i][0],&inp[i][1],&inp[i][2]);
        }

        //dp[0][0]=0;
        dp[0][1]=inp[0][1];
        dp[0][2]=inp[0][2]+dp[0][1];
        dp[1][0]=inp[1][0]+dp[0][1];
        dp[1][1]=min(min(dp[0][1],dp[0][2]),dp[1][0])+inp[1][1];
        dp[1][2]=min(min(dp[0][1],dp[0][2]),dp[1][1])+inp[1][2];

        for(int i=2;i<t;i++)
        {
            dp[i][0]=inp[i][0]+min(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=inp[i][1]+min(min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2]),dp[i][0]);
            dp[i][2]=inp[i][2]+min(min(dp[i-1][1],dp[i-1][2]),dp[i][1]);
        }

        printf("%d. %d\n",case_++,dp[t-1][1]);
    }
    return 0;
}
