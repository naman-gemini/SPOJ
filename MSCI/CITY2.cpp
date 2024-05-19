#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t,**a;
    int caseno=1;
    while(scanf("%d",&t)==1)
    {
        a=(int**)malloc(sizeof(int*)*2);
        a[0]=(int*)malloc(sizeof(int)*t);
        a[1]=(int*)malloc(sizeof(int)*t);

        for(int i=0;i<t;i++)
        {
            scanf("%d",&a[0][i]);
            a[1][i]=0;
            //0 flag means not calculated yet
        }
        int count=0;

        for(int i=0;i<t;i++)
        {
            if(!a[1][i] && a[0][i])
            {
                //a[1][i]=1;
                for(int j=i+1;j<t;j++)
                {
                    if(a[0][j]==a[0][i])
                    a[1][j]=1;

                    if(a[0][j]<a[0][i])
                    break;
                }
                count++;
            }
        }
        printf("Case %d: %d\n",caseno,count);
        caseno++;
        free(a[0]);
        free(a[1]);
    }
    return 0;
}
