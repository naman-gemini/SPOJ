#include<stdio.h>

int main()
{
    int test_cases;
    long long A;
    double out1,out2;

    scanf("%d",&test_cases);
    while(test_cases--)
    {
        scanf("%lld",&A);
        if(A==1) out1=2.0/3;

        else
        {
            out1=1.0/(2*(A+1));
            out2=1.0/(2*(A+2));
            out1=3.0/4-out1+out2;
        }

        printf("%.11lf\n",out1);
    }

    return 0;

}
