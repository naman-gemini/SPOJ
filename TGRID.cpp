#include<cstdio>

int main()
{
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);

        if(n>m)
        {
            if(m%2 ==1) printf("D\n");
            else printf("U\n");
        }

        else if(n<=m)
        {
            if(n%2 ==1) printf("R\n");
            else printf("L\n");
        }
    }
    return 0;
}
