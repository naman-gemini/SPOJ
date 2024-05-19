#include<cstdio>
#include<algorithm>
using namespace std;
int a[100000];
int main()
{
    int t,n,m;
    int ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(binary_search(a,a+n,m-a[i]))
            ans++;
        }
        printf("%d\n",ans/2);
    }
    return 0;
}
