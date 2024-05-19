#include<cstdio>
#include<cmath>

int cs = 1;
int main()
{
    double P,I,total;
    int c;

    while(scanf("%lf %lf %d",&P,&I,&c) == 3 && (P || I || c))
    {
        int cents = (int)(100*P + 0.5);
        for(int i =0; i<c; i++)
        {
            total = cents*(1 + I/(100*c));
            if (fabs (total - (int)(total+0.5)) < 1e-5)
                cents = (int)(total+0.5);
            else cents = (int) total;
        }

        printf ("Case %d. $%.2f at %.2f%% APR compounded %d times yields $%.2f\n",cs++,P,I,c,cents/100.0);
    }

    return 0;

}
