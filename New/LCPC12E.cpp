#include<cstdio>
#include<cmath>

int main()
{
    double x,y,z,w,r1,r2,x1,y1,x2,y2,d;
    int t,cs;
    scanf("%d",&t);
    for( cs=1; cs<=t; cs++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&r1,&r2);
        r2/=sqrt(2);
        d=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        if(d>r1+r2)
            printf("%d. No problem\n",cs);
        else
        {
            x=-d+r1-r2;
            y=-d-r1+r2;
            z=-d+r1+r2;
            w=d+r1+r2;
            x=sqrt(x*y*z*w);
            x/=(d*1.0);
            printf("%d. %.3lf\n",cs,x);
        }

    }
    return 0;
}

