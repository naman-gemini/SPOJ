#include<stdio.h>
#include<math.h>

int prime(int num)
{
    int i,flag=1;
    if(num==1) return 0;
    if(num==2) return 1;
    if(num%2 ==0) return 0;

    for(i=3; i<=(int)(sqrt(num)); i+=2)              // flag=1 if prime;
    {
        if(num%i==0)
            flag=0;
    }
    return flag;
}

int main()
{
    int t,n1,n2,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n1,&n2);
        for(i=n1;i<=n2;i++)
        {
            if(prime(i)) printf("%d\n",i);
        }
        printf("\n");
    }
    return 0;
}
