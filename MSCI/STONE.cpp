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

        int x0,y0;
        int x,y;
        int xn,yn;


        scanf("%d %d",&x0,&y0);
        xn=x0;
        yn=y0;
        double cx=0,cy=0,a=0;

        for(int i=1; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            a+=(x0*y-x*y0);
            cx+=(x0+x)*(x0*y-x*y0);
            cy+=(y0+y)*(x0*y-x*y0);
            x0=x;
            y0=y;
        }

        a+=(x0*yn-xn*y0);
        cx+=(x0+xn)*(x0*yn-xn*y0);
        cy+=(y0+yn)*(x0*yn-xn*y0);


        a/=2.0;
        cx/=6.0*a;
        cy/=6.0*a;

        if(abs(cx)<0.005) cx=0;
        if(abs(cy)<0.005) cy=0;

        printf("%.2lf %.2lf\n",cx,cy);
    }
    return 0;
}
