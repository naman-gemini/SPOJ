#include<stdio.h>
#include<math.h>

int main()
{
    int counter;
    long long int i,j,n,x,p,sum,q;
    for(x=0; x<50; x++)
    {
        counter=0;
        scanf("%lld",&n);
        p=(long long)(sqrt(n/2));
        q=(long long)(sqrt(n));
        for(i=0; i<=p; i++)
            for(j=q; j>=p; j--)                 //considering i to be smaller number and j to be larger
            {                                   //i^2+j^2=n so 0<=i<=sqrt(n/2) sqrt(n)>=j>=sqrt(n/2)
                sum=i*i+j*j;
                if(n==sum)
                    counter++;
                if(sum<n)
                    break;
            }
        printf("%d\n",counter);
    }
    return 0;
}
