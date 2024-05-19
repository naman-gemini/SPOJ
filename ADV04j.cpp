#include<cstdio>
#include<cmath>
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%.0f\n",ceil(log2(n))+1);
    }
    return 0;
}
