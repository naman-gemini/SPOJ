#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

char a[100005];
vector<int> v;
vector<int>::iterator it;

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        int max=1;
        scanf("%d",&m);
        scanf("%s",a);
        n=strlen(a);
        for(int i=0;i<n;i++)
        {
            if(a[i+1]==a[i]) max++;
            else
            {
                v.push_back(max);
                max=1;
            }
        }
        sort(v.rbegin(),v.rend());
        int sum=0;
        for(it=v.begin();it!=v.end() && m>0;it++,m--)
        sum+=*it;
        printf("%d\n",sum);
    }
    return 0;
}
