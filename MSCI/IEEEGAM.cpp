#include<cstdio>
using namespace std;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        double ans;
        scanf("%d",&n);
        if(n==1)
        {
            ans=1.0/2.0;
        }
        else
        {
            ans=float(n)/(n+1);
        }

        printf("%.8lf\n",ans);
    }
    return 0;
}
