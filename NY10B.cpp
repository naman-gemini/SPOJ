#include<cstdio>

int nim_sum(int b,int x, int y)
{
    int result,dig1,dig2;
    int mult= 1;
    result = 0;
    while(x != 0 || y != 0)
    {
        dig1 = x%b;
        dig2 = y%b;
        x /= b;
        y /= b;
        result += ((dig1 + dig2)%b)*mult;
        mult *= b;
    }

    return result;
}

int main()
{
    int p,x,y,b;

    scanf("%d",&p);
    int cs;
    while(p--)
    {
        scanf("%d %d %d %d",&cs,&b,&x,&y);

        int res = nim_sum(b,x,y);

        printf("%d %d\n",cs,res);
    }

    return 0;
}
