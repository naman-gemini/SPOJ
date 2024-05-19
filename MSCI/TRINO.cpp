#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int t;
    long long m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&m,&n);
        if(m==1 || n==1)
        {
            printf("0\n");
            continue;
        }
        printf("%lld\n",(m*n)/2);
    }
    return 0;
}
