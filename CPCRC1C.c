#include<stdio.h>
#define range1 45
#define range2 900
#define range3 13500
#define range4 180000
#define range5 2250000
#define range6 27000000
#define range7 315000000
#define range8 3600000000

long long int sum_digits(int a)
{
    int n,sum=0;
    do
    {
        n=a%10;
        sum+=n;
        a=a/10;
    }
    while(a!=0);
    return sum;
}

int digit_len(int num)
{
    int count=1;
    while((num/10)!=0)
    {
        count++;
        num/=10;
    }
    return count;
}

int main()
{
    int a,b,i,digit_a,digit_b;
    long long unsigned suma,sumb;
    while(1)
    {
        suma=0;sumb=0;
        scanf("%d",&a);
        digit_a=digit_len(a);
        scanf("%d",&b);
        digit_b=digit_len(b);

        if(a==-1 && b==-1) return 1;

        else if (a==0 && b==0) printf("0\n");

        else if (a==b) printf("%d\n",b);

        else
        {
            switch (digit_a)
            {
                case 1:
                for(i=1;i<a;i++) suma+=sum_digits(i);
                break;

                case 2:
                suma=range1;
                for(i=10;i<a;i++) suma+=sum_digits(i);
                break;

                case 3:
                suma=range2;
                for(i=100;i<a;i++) suma+=sum_digits(i);
                break;

                case 4:
                suma=range3;
                for(i=1000;i<a;i++) suma+=sum_digits(i);
                break;

                case 5:
                suma=range4;
                for(i=10000;i<a;i++) suma+=sum_digits(i);
                break;

                case 6:
                suma=range5;
                for(i=100000;i<a;i++) suma+=sum_digits(i);
                break;

                case 7:
                suma=range6;
                for(i=1000000;i<a;i++) suma+=sum_digits(i);
                break;

                case 8:
                suma=range7;
                for(i=10000000;i<a;i++) suma+=sum_digits(i);
                break;

                case 9:
                suma=range8;
                for(i=100000000;i<a;i++) suma+=sum_digits(i);
                break;

                case 10:
                suma=range8+1;
                break;

            }

            switch (digit_b)
            {
                case 1:
                for(i=1;i<=b;i++) sumb+=sum_digits(i);
                break;

                case 2:
                sumb=range1;
                for(i=10;i<=b;i++) sumb+=sum_digits(i);
                break;

                case 3:
                sumb=range2;
                for(i=100;i<=b;i++) sumb+=sum_digits(i);
                break;

                case 4:
                sumb=range3;
                for(i=1000;i<=b;i++) sumb+=sum_digits(i);
                break;

                case 5:
                sumb=range4;
                for(i=10000;i<=b;i++) sumb+=sum_digits(i);
                break;

                case 6:
                sumb=range5;
                for(i=100000;i<=b;i++) sumb+=sum_digits(i);
                break;

                case 7:
                sumb=range6;
                for(i=1000000;i<=b;i++) sumb+=sum_digits(i);
                break;

                case 8:
                sumb=range7;
                for(i=10000000;i<=b;i++) sumb+=sum_digits(i);
                break;

                case 9:
                sumb=range8;
                for(i=100000000;i<=b;i++) sumb+=sum_digits(i);
                break;

                case 10:
                sumb=range8+1;
                break;

            }

            printf("%lld\n",sumb-suma);
        }

    }
    return 0;

}
