#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    long long int n,i;
    double result;
    scanf("%d",&t);
    while(t--)
    {
        result=0;
        scanf("%lld",&n);
        if(n==0 || n==1) printf("1\n");
        else
        {
        result=n*log(n)-n+ log(2*M_PI*n)/2;
        result=result*log10(M_E);
        printf("%lld\n",(long long int)(result)+1);
        }
    }
    return 0;
}
