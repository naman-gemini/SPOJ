#include<cstdio>
#include<algorithm>
using namespace std;

int dp[10005];

int main()
{
    int t,n;
    int empty,full;
    int W;
    int weight,value;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&empty,&full);
        W=full-empty;
        scanf("%d",&t);
        int types[502][2];
        for(int i=0; i<t; i++)
        {
            scanf("%d %d",&types[i][0],&types[i][1]);

        }
        dp[0] = 0;
        for(int i = 1; i<=W; i++)
        {
            int min = 500000;
            for(int j = 0; j<t; j++)
            {

                if(types[j][1]<=i)
                {
                    int t = dp[i-types[j][1]]+types[j][0];
                    if(min>t)
                        min = t;
                }

            }
            dp[i] = min;


        }

        //printf("Min : %d\n",dp[W]);

        if(dp[W]!=500000)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[W]);
        else
            printf("This is impossible.\n");

    }
    return 0;
}

