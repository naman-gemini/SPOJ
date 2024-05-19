#include<cstdio>
#include<algorithm>
using namespace std;

int M[55];
int W[55];
int value[55][1010];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k,m;
        scanf("%d %d",&k,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&M[i],&W[i]);
        }

        for(int i=0;i<=m;i++)
        {
            value[i][0]=0;
        }
        for(int j=0;j<=k;j++)
        {
            value[0][j]=0;
        }


        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(M[i]>j)
                value[i][j]=value[i-1][j];

                else
                value[i][j]=max(value[i-1][j],value[i-1][j-M[i]]+W[i]);
            }
        }

        printf("Hey stupid robber, you can get %d.\n",value[m][k]);
    }
    return 0;
}
