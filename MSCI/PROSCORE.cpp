#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int t,n,p,cs;
    bool flag1,flag2,flag2_temp,flag3,flag3_temp;
    int *a;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        flag1=false,flag2=true,flag3=true;
        scanf("%d %d",&n,&p);
        a=(int *)malloc(sizeof(int)*p);
        for(int i=0; i<n; i++)
        {
            flag2_temp=false;
            flag3_temp=false;
            for(int j=0; j<p; j++)
            {
                scanf("%d",&a[j]);
            }

            for(int j=0; j<p; j++)
            {
                if(flag1==false)
                    if(a[j]==1)
                    {
                        flag1=true;
                        break;
                    }
            }

            for(int j=0; j<p; j++)
            {
                if(flag2==true)
                {
                    if(a[j]==1)
                    {
                        flag2_temp=true;
                        break;
                    }
                }
            }
            if(flag2_temp==false) flag2=false;

            for(int j=0; j<p; j++)
            {
                if(flag3==true)
                    if(a[j]==0)
                    {
                        flag3_temp=true;
                        break;
                    }
            }
            if(flag3_temp==false) flag3=false;
        }
        printf("Case %d: %d\n",cs,(int)flag1*4+(int)flag2*2+(int)flag3);
        free(a);
    }
    return 0;
}

