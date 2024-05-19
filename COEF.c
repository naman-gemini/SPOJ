#include<stdio.h>

int fact(int n)
{
    int i,product=1;
    for(i=1;i<=n;i++)
    product=i*product;
    return product;
}

int main()
{
    int n,k,p;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        int output=fact(n);
        while(k--)
        {
            scanf("%d",&p);
            output=output/fact(p);
        }
        printf("%d\n",output);
    }
    return 0;
}
