#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);

        long long int x0,y0;
        long long int x,y;
        long long int xn,yn;


        scanf("%lld %lld",&x0,&y0);
        xn=x0;
        yn=y0;
        long long int cx=0,cy=0,a=0;

        for(int i=1; i<n; i++)
        {
            scanf("%lld %lld",&x,&y);
            a+=(x0*y-x*y0);
            cx+=(x0+x)*(x0*y-x*y0);
            cy+=(y0+y)*(x0*y-x*y0);
            x0=x;
            y0=y;
        }

        a+=(x0*yn-xn*y0);
        cx+=(x0+xn)*(x0*yn-xn*y0);
        cy+=(y0+yn)*(x0*yn-xn*y0);

        double ai,ci,cj;
        ai=a/2.0;
        ci=cx/(6.0*ai);
        cj=cy/(6.0*ai);

        //printf("%lf %lf %lf\n",ai,ci,cj);
        if(abs(ci)<0.005) ci=0;
        if(abs(cj)<0.005) cj=0;

        printf("%.2lf %.2lf\n",ci,cj);
    }
    return 0;
}

