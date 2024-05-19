#include <cstdio>
#include <algorithm>
using namespace std;

pair< int, int > a[100000];

bool comp(const pair< int, int > &x, const pair< int, int > &y)
{
    if(x.second==y.second) return (x.first<y.first);
    else return (x.second<y.second);
}

int main()
{
    int t, i, n, prev, ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        scanf("%d %d", &a[i].first, &a[i].second);

        sort(a, a + n, comp);
        ans = 0;
        prev = -1;

        for(i = 0; i < n; i++)
        {
            if(a[i].first >= prev)
            {
                prev = a[i].second;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
