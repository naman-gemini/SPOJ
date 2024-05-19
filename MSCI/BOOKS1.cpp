#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;

const int MAXN = 501, INFINITY = 1<<30;
int k, m;
int64 p[MAXN], s[MAXN];
bool bar[MAXN];

bool is_valid(int64 x)
{
    int i, j, c=0, tmp;

    for(j=m; j>=1; j=tmp)
    {
        tmp = 0;
        for(i=j; i>=1; i--)
        {
            if(s[j]-s[i-1] > x)
            {
                tmp = i;
                break;
            }
        }
        c++;
    }

    return c <= k;
}

int64 bs(int64 b, int64 e)
{
    int64 m = (b+e)/2;
    return b<e ? (is_valid(m) ? bs(b,m) : bs(m+1,e)) : e;
}

void build_solution(int64 x)
{
    int i, j, c = 0;
    int tmp;

    fill(bar+1, bar+1+m, false);

    for(j=m; j>=1; j=tmp)
    {
        tmp = 0;
        for(i=j; i>=1; i--)
        {
            if(s[j]-s[i-1] > x)
            {
                tmp = i;
                break;
            }
        }
        c++;
        bar[tmp+1] = true;
    }

    for(tmp=1; c<k; tmp++)
    {
        if(!bar[tmp+1])
        {
            bar[tmp+1]=true;
            c++;
        }
    }
}

int main()
{
    int i, t;
    int64 avg, maxp, x;

    p[0] = s[0] = 0;
    scanf("%d", &t);
    while(t--)
    {
        // input
        scanf("%d %d", &m, &k);
        maxp = -1;
        for(i=1; i<=m; i++)
        {
            scanf("%lld", &p[i]);
            s[i] = s[i-1] + p[i];
            maxp = max(maxp, p[i]);
        }
        avg = max(s[m]/m, maxp);

        x = bs(avg, s[m]);
        build_solution(x);

        // output
        printf("%lld", p[1]);
        for(i=2; i<=m; i++)
        {
            if(bar[i]) printf(" /");
            printf(" %lld", p[i]);
        }
        printf("\n");
    }

    return 0;
}
