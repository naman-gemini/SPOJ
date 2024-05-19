#include<cstdio>
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1 || n==2)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",n-2);
    }
    return 0;
}
