#include<stdio.h>
#include<math.h>

int main()
{
    int t,a,b,c;
    double T,ea,eb,ec,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        s=(a+b+c)/2.0;
        T=sqrt(s*(s-a)*(s-b)*(s-c));
        ea=(sqrt(3)*a*a)/4.0;
        eb=(sqrt(3)*b*b)/4.0;
        ec=(sqrt(3)*c*c)/4.0;
        printf("%.2lf\n",1.5*T+(ea+eb+ec)/2.0);
    }
    return 0;
}
