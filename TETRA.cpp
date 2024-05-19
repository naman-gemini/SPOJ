#include<stdio.h>
#include<math.h>

double area( double a,  double b, double c)
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    int t,i,a,b,c,d,e,f;
    double v,A,B,C,S;
    double r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
        A= (double)(c*c+e*e-a*a)/(2*c*e);
        B= (double)(e*e+f*f-d*d)/(2*e*f);
        C= (double)(f*f+c*c-b*b)/(2*f*c);
        v= (c*e*f)*(sqrt(1+2*A*B*C-A*A-B*B-C*C))/6;
        S= area(d,e,f)+area(a,c,e)+area(a,b,d)+area(b,f,c);
        r = 3*v/S;
        printf("%.4f\n",r);
    }

    return 0;
}
