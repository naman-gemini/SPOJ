#include<stdio.h>

int main()
{
    int test,n,t1,t,x,temp,i=1;
    long long int sum,a,b;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %lld %lld",&n,&a,&b);
        sum=2*a;
        scanf("%d",&t1);
        temp=t1;
        int p=n-1;
        while(p--)
        {
            scanf("%d",&t);
            x=t-temp;
            if((x-1)*b  <=  2*a)
            sum+=((x-1)*b);
            else
            sum+=(2*a);
            temp=t;
        }
        sum+=n*b;
        printf("Case #%d: %lld\n",i,sum);
        i++;
    }
    return 0;
}
