#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    double a,b,c,d,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        s=(a+b+c+d)/2;
        printf("%lf\n",sqrt((s-a)*(s-b)*(s-c)*(s-d)));
    }
    return 0;
}
