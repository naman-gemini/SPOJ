#include<stdio.h>

int exp(int base,int exponent,int modulus)
{
    int result=1;
    while(exponent>0)
    {
        if(exponent&1)
        result = (result * base) % modulus;
        exponent/=2;
        base = (base*base)%modulus;
    }
    return result;
}

int main()
{
    int x,z,k,y;
    while(1)
    {
        scanf("%d %d %d",&x,&z,&k);
        if(x==0 && z==0 && k==0) return 0;

        int p=k%z;
        int i,flag=1;
        for(y=1;y<=z;y++)
        {
            if(exp(x,y,z)==p)
            {
                printf("%d\n",y);
                flag=0;
                break;
            }
        }
        if(flag) printf("No Solution\n");
    }
    return 0;
}
