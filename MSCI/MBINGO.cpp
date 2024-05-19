#include<cstdio>
#include<cstdlib>
using namespace std;

int a[2][95];

void empty(int n)
{
    for(int i=0;i<=n;i++)
    {
        a[0][i]=0;
        a[1][i]=0;
    }
}

bool check(int n)
{
    bool flag=true;
    for(int i=0;i<=n;i++)
    {
        if(a[0][i]==0) flag=false;
    }
    return flag;
}

int main()
{
    int n,b;
    while(1)
    {
        scanf("%d %d",&n,&b);
        if(n==0 && b==0) break;

        empty(n);

        for(int i=0;i<b;i++)
        {
            scanf("%d",&a[1][i]);
        }

        for(int i=0;i<b;i++)
        {
            a[0][a[1][i]]=1;
        }

        if(check(n))
        {
            printf("Y\n");
            continue;
        }

        for(int i=0;i<b-1;i++)
        {
            for(int j=i+1;j<b;j++)
            {
                a[0][abs(a[1][i]-a[1][j])]=1;
            }
        }

        if(check(n)) printf("Y\n");
        else printf("N\n");
    }
}
