#include<stdio.h>
#define MOD 1000000007
typedef long long ll;
ll arr[1000005];

void precal()
{
    int i;
    for(i=3;i<=1000000;i++)
    {
        arr[1]=0;
        arr[2]=1;
        arr[i]=((i-1)*(arr[i-2]+arr[i-1]))%MOD;
    }
}

int main()
{
    int t,n;
    scanf("%d",&t);
    precal();
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",arr[n]);
    }
    return 0;
}
