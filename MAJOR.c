#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t,n,i,max,result;
    scanf("%d",&t);
    while(t--)
    {
        int *num,*b;
        max=0;
        result=0;
        scanf("%d",&n);
        num=(int*)malloc(n*sizeof(int));

        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }

        b=(int*)malloc(2005*sizeof(int));

        for(i=-1000;i<=1000;i++)
        b[i+1000]=0;

        for(i=0;i<n;i++)
        {
            b[num[i]+1000]++;
            if(b[num[i]+1000] > max)
            {
                max=b[num[i]+1000];
                result=num[i]+1000;
            }
        }
        if(max > n/2) printf("YES %d\n",result-1000);
        else printf("NO\n");
        free(num);
        free(b);
    }
    return 0;
}
