#include<cstdio>


int main()

{
    int n,m;

    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0 && m==0) break;
        if(n>m) printf("0.000000\n");
        else printf("%.6lf\n",(double)(m-n+1)/(m+1));
    }

    return 0;
}
