#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    long long int a,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&a);
        if(a==2 || a==3) {printf("YES\n"); continue;}
        if(a%2==0) {printf("NO\n"); continue;}
        else
        for(i=3;i<=floor(sqrt(a));i+=2)
        {
            if(a%i==0)
            {
                printf("NO\n");
                break;
            }
        }
        if(a%i !=0) printf("YES\n");
    }
    return 0;
}
