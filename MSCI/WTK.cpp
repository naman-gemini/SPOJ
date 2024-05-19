#include <cstdio>

int main()
{
    int n,k,ans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans = 0;
        n++;
        k=n;
        for (int i=1;i<n;i++)
        {
            ans=(ans+k)%(i + 1);
        }
        printf("%d\n",ans + 1);
    }
    return 0;
}
