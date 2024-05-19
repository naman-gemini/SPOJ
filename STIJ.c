#include<stdio.h>

int main()
{
    int i,b,x,sum,max=0;

    while(1)
    {
        scanf("%d",&b);
        if(b==0) break;

        sum=0;
        while(b--)
        {
            scanf("%d",&x);
            sum+=x;
            if(x>max) max=x;
        }
        if(max>sum/2) i=sum;
        else if (max==1) i=sum;
        else
        for(i=max;i<=sum/2;i++)
        {
            if(sum%i==0)
            break;
        }
        if(sum%i==0) printf("%d\n",i);
        else printf("%d\n",sum);
    }
    return 0;
}
