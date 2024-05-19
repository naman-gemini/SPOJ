#include<iostream>
#include<cstdio>
using namespace std;

void solve(int a,int b)
{
    while(a != 1 || b!=1)
    {
        if(a > b)
        {
            putchar('R');
            a -= b;
            a ^= b;
            b ^= a;
            a ^= b;

        }
        else
        {
            putchar('L');
            a ^= b;
            b ^= a;
            a ^= b;
            a -= b;
        }
    }

    printf("\n");
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int a,b;
        scanf("%d/%d",&a,&b);
        solve(a,b);
    }

    return 0;
}
