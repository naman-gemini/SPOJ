#include<stdio.h>
#include<math.h>

double factorial ( long long int x)
{
     if (x==0) return 1;
     else
     return x* factorial(x-1);
}

double f(int x)
{
     if(x==1)
     return 0;
     
     else if ((x%2)==0)
     return f(x-1) + (factorial(x-1))/((factorial(x/2))*(factorial(x/2-1)));
     
     else
     return f(x-1);
     
}


int main()
{
     int N,power;
     double given_number;
     scanf("%d",&N);
     while (N--)
     {
           //scanf("%lld",&given_number);
           given_number=1152921504606846976;
           power=log2(given_number);
           printf("%lf\n",f(power));
     }
     
     return 0;
}
