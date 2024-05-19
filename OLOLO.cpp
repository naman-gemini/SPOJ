#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

int main ()
{
    int t,n,ans;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        if(i==0) ans=n;
        else ans^=n;
    }
    printf("%d\n",ans);
    return 0;
}
