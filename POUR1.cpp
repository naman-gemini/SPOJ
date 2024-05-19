#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int operate(int a , int b, int c)
{
    int moves=0,b1=0,b2=0;
    while(b1!=c && b2!=c)
    {
        if(b1==0)
        {
            b1=a;
            moves++;
            continue;
        }
        if(b2==b)
        {
            b2=0;
            moves++;
            continue;
        }
        int low = min(b1,b-b2);
        {
            b1 = b1-low;
            b2 = b2+low;
            moves++;
        }
    }
    return moves;
}

int main()
{
    int t;
    int a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);

        if(c>a && c>b)
        {
            printf("-1\n");
            continue;
        }

        if(c==0)
        {
            printf("0\n");
            continue;
        }

        if(c==a || c==b)
        {
            printf("1\n");
            continue;
        }

        if(c%gcd(a,b)!=0)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",min(operate(a,b,c),operate(b,a,c)));
    }
    return 0;
}
