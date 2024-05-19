#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int *a;
        a=(int*)malloc(n*sizeof(int));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                count++;
            }
        }
        printf("%d\n",count);
    }
}
