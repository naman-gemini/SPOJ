#include<stdio.h>
int main()
{
    int t,i,j,k,flag,a[100];
    char ar[101],test;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        j=0;
        flag=0;
        while(j<99)
        {
            scanf("%d %c",&a[j],&ar[j]);
            j++;
        }
        for(k=9; k<99; k++)
        {
            test=ar[k];
            k=a[k]-(a[k]/10+a[k]%10);
            if(test!=ar[k])
            {
                flag=1;
                printf("NO\n");
                break;
            }
        }
        if(flag==0)
            printf("YES\n");
    }
    return 0;
}
