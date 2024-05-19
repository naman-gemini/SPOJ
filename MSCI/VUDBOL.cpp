#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
vector<ull> fib;
vector<ull> ans;
vector<ull>::iterator it;

int main()
{
    int n;
    fib.push_back(0);
    fib.push_back(1);
    for(int i=2;i<50;i++) fib.push_back(fib[i-1]+fib[i-2]);
    while(scanf("%d",&n) && n!=0)
    {
        while(n--)
        {
            int val;
            scanf("%d",&val);
            it=lower_bound(fib.begin(),fib.end(),val);
            if((*it-val)>(val-*(it-1))) ans.push_back(*(it-1));
            else ans.push_back(*it);
        }
        sort(ans.begin(),ans.end());
        for(it=ans.begin();it!=ans.end();it++)
            printf("%d ",*it);
        printf("\n");
        ans.clear();
    }
    fib.clear();
    return 0;
}
