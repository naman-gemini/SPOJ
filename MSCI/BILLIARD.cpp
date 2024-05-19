//algo: physics

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int a,b,s,m,n;
    double angle,distance,vx,vy;
    while(1)
    {
        scanf("%d %d %d %d %d",&a,&b,&s,&m,&n);
        if(a==0 and b==0 and s==0 and m==0 and n==0) break;
        vx=((double)m*a)/s;
        vy=((double)n*b)/s;
        angle=atan(vy/vx)*180/M_PI;

        printf("%.2lf %.2lf\n",angle,sqrt(vx*vx+vy*vy));
    }

    return 0;
}
