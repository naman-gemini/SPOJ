#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

vector<int> v;

int main()
{
    while(1)
    {
        v.clear();
        int t,temp;
        long long int ans=0;
        scanf("%d",&t);
        if(t==0) break;
        if(t==1)
        {
            scanf("%d",&temp);
            printf("0\n");
            continue;
        }
        while(t--)
        {
            scanf("%d",&temp);
            v.push_back(temp);
        }
        int mid;
        int n=v.size();
        if(n%2==1) mid=v[(n-1)/2];
        else mid=(v[n/2]+v[n/2-1])/2;

        for(int i=0;i<(n/2);i++)
        {
            ans+=(mid-((n/2)-i)-v[i]);
        }
        for(int i=n/2 ;i<n;i++)
        {
            ans+=(v[i]-((i-(n/2))+mid));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
