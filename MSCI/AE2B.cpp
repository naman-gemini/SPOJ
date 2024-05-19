#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
    int t;
    int k,n,x1,y1,x2,y2;
    int x,y;
    int g;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&k,&n,&x1,&y1,&x2,&y2);
        g=gcd(k,n);
        x = x1 > x2? x1 - x2 : x2 - x1;
        y = y1 > y2? y1 - y2 : y2 - y1;

        if(g > 1)
        {
            if(x%g!=0 || y%g!=0)
            {
                printf("NIE\n");
                continue;
            }
            k/=g,n/=g,x/=g,y/=g;
        }

        if(k%2==0 || n%2==0) printf("TAK\n");
        else if((x%2 + y%2) == 1) printf("NIE\n");
        else printf("TAK\n");
    }
    return 0;
}
