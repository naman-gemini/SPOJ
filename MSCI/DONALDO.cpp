#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int>::iterator it;

int main()
{
    int count,sum;
    int t,n,cs;
    int I,hr,min,sec;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        v.clear();
        scanf("%d",&n);
        count=n;
        sum=0;
        int *a=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
        {
            scanf("%d:%d:%d",&hr,&min,&sec);
            a[i]=3600*hr+60*min+sec;
            printf("%d ",a[i]);
        }

        scanf("%d",&I);
        sort(a,a+n);
        for(int i=0;i<n-1;i++) v.push_back(a[i+1]-a[i]);
        if(v.size()==1)
        {
            //printf("count=%d\n",count);
            if(*(v.begin())>=I) count--;
            printf("Case %d: %d\n",cs,count);
            continue;
        }
        for(it=v.begin();it!=v.end();it++)
        {
            if(sum>=I)
            {
                sum=0;
                count--;
            }
            else
            {
                sum+=*it;
            }
        }
        if(sum>=I) count--;
        printf("Case %d: %d\n",cs,count);
        free(a);
    }
    return 0;
}
