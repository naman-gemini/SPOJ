#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
    int t,n;
    int count,ans;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        ans=0;
        scanf("%d",&n);
        int *a=(int *)malloc(sizeof(int)*n);
        int *b=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);

        for(int i=0,j=0;i<n && j<n;)
        {
            if(a[i]<b[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            ans=max(ans,count);
        }

        printf("%d\n",ans);

        free(a);
        free(b);
    }
    return 0;
}
