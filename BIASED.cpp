#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;

char names[100000];
long long int ranks[100000];

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        char nm[1000];
        int p;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%s %lld",nm,&ranks[i]);

        }
        sort(ranks,ranks+n);

        long long int res = 0;

        for(int i=0; i<n; i++)
        {
            res += fabs(ranks[i] - (i+1));
        }

        printf("%lld\n",res);

    }

    return 0;
}

