#include<stdio.h>


int max(int a[],int size)
{
    int i,max=0,pos;
    for(i=0;i<size;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            pos=i;
        }
    }
    return pos;
}

int main()
{
    int t,n,m,D,i,flag;
    int k;
    int hero[500];
    scanf("%d",&t);
    while(t--)
    {
        flag=1;
        scanf("%d %d %d",&n,&m,&D);
        i=0;
        while(n--)
        {
            scanf("%d",&hero[i]);
            i++;
        }

        while(m--)
        {
            int val;
            val=max(hero,i);
            hero[val]-=D;

            if(hero[val]<=0)
            {
                printf("NO\n");
                flag=0;
                break;
            }
        }

        if(flag==1) printf("YES\n");

    }
}
