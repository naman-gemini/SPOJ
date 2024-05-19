#include<stdio.h>


int main()
{
    int i,j,s,sum,flag=0,N[11000],num[11000],counter[11000],avg;
    for(i=0;; i++)
    {
        counter[i] =0;
        scanf("%d",&N[i]);
        if(N[i]!=-1)
        {
            sum=0;
            for(j=0; j<N[i]; j++)
            {
                scanf("%d",&num[j]);
                sum+=num[j];
            }
            if(sum%N[i]==0)
            {
                avg=sum/N[i];
                for(j=0; j<N[i]; j++)
                {
                    if(num[j]<avg)
                        counter[i]+=(avg-num[j]);
                }
            }
            else
                counter[i]=-1;
            flag++;
        }
        else
            break;
    }
    for(i=0; i<flag; i++)
    {
        printf("%d\n",counter[i]);
    }
    return 0;
}
