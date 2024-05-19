#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;
int dp1[1555];
int dp2[1555];
int R[1555];
int P[1555];
int pre[1555];

int main()
{
    int t,balls,idx;
    long long res;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d",&balls);
        for(int i=1; i<=balls; i++) scanf("%d%d",&R[i],&P[i]);
        memset(dp1,0,sizeof(dp1));memset(dp2,0,sizeof(dp2)); memset(pre,0,sizeof(pre));
        dp1[1]=1;
        dp2[1]=P[1];
        for(int i=1; i<=balls; i++)
        {
            for(int j=i-1; j>=1; j--)
            {
                if(dp1[j]+1 > dp1[i] and R[i] > R[j])
                {
                    dp1[i]=dp1[j]+1;
                    dp2[i]=dp2[j]+P[i];
                    pre[i]=j;
                }
                else if(dp1[j]+1==dp1[i] and P[i]+dp2[j]> dp2[i] and R[i] > R[j])
                {
                    dp2[i]=dp2[j]+P[i];
                    pre[i]=j;

                }

            }
            if(dp1[i]==0) dp1[i]=1, dp2[i]=P[i];


        }

        //for(int i=1; i<=balls; i++) printf("%d %d\n",dp1[i],dp2[i]);
        res=0;idx=0;
        for(int i=balls;i>=1;i--)
            if(dp1[i]> res) res=dp1[i],idx=i;
            else if(dp1[i]==res and dp2[i]>dp2[idx])
                idx=i;

        vector<int> order;
        while(idx!=0){
            order.push_back(idx); idx=pre[idx];
        }
        reverse(order.begin(),order.end());
        printf("%d. ",cs);
        for(int i=0;i<order.size();i++)
            printf("%d ",order[i]);
        putchar('\n');

    }
    //printf("%d\n",2000000*1500);
    return 0;
}
