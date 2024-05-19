#include <cstdio>
#include <cmath>
typedef long long ll;

using namespace std;
int main()
{
    ll N;
    int t;
    int i,min,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&N);
        i = ceil(log2(N));
        for(int k=0; k<=i; k++)
        {
            temp = N>>k;
            if(temp&1==1)
            {
                min = k;
                break;
            }
        }
        printf("%lld %d\n",(ll)pow(2,i),i-min);
    }
    return 0;
}
