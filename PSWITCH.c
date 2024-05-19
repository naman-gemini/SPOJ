#include<stdio.h>
int total[101],on[101],off[101],N,value[101];

void f(int a,int b,int c,int d)
{
    int i,flag;

    for(i=0;i<=N;i++)                               //initializing arrays
        total[i]=1;

    if(a==1)
    {
        for(i=1;i<=N;i++)
        total[i]=!total[i];
    }

    if(b==1)
    {
        for(i=1;i<=N;i+=2)
        total[i]=!total[i];
    }

    if(c==1)
    {
        for(i=2;i<=N;i+=2)
        total[i]=!total[i];
    }

    if(d==1)
    {
        for(i=1;i<=N;i+=3)
        total[i]=!total[i];
    }

    {
        flag=1;

        for(i=1;on[i]!=-1;i++)
        if(total[on[i]]!=1) flag=0;

        for(i=1;off[i]!=-1;i++)
        if(total[off[i]]!=0) flag=0;

        if(flag==1)
        {
            for(i=1;i<=N;i++)
            printf("%d",total[i]);
            printf("\n");
        }
    }
}

int main()
{
    int C,i;
    scanf("%d",&N);
    scanf("%d",&C);

    for(i=0;i<=N;i++)                               //initializing arrays
        total[i]=1;

    for(i=0;i<=N;i++)
        on[i]=0;

    for(i=0;i<=N;i++)
        off[i]=0;

    for(i=1;;i++)
    {
        scanf("%d",&on[i]);
        if(on[i]==-1) break;
    }


    for(i=1;;i++)
    {
        scanf("%d",&off[i]);
        if(off[i]==-1) break;
    }

    if(C==1)
    {
        f(0,0,0,1);
        f(0,0,1,0);
        f(0,1,0,0);
        f(1,0,0,0);
        return 0;
    }

    if(C==2)
    {
        f(0,0,1,1);
        f(0,1,0,1);
        f(0,1,1,0);
        f(1,0,0,1);
        f(1,0,1,0);
        f(1,1,0,0);
        return 0;
    }

    if(C%2==0)
    {
        f(0,0,0,0);
        f(0,0,1,1);
        f(0,1,0,1);
        f(0,1,1,0);
        f(1,0,0,1);
        f(1,0,1,0);
        f(1,1,0,0);
        f(1,1,1,1);
    }

    else
    {
        f(0,0,0,1);
        f(0,0,1,0);
        f(0,1,0,0);
        f(0,1,1,1);
        f(1,0,0,0);
        f(1,0,1,1);
        f(1,1,0,1);
        f(1,1,1,0);
    }

    return 0;
}
