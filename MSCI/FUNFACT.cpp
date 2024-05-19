#include<cstdio>
#include<cmath>
using namespace std;

int num(int n)
{
    if (n==1 || n==2) return 1;
    double sum=0;
    for(int i=2;i<=n;i++) sum+=log10(i);
    return int(ceil(sum));
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        scanf("%d",&x);
        //printf("%d\n",num(x));
        for(int i=1;;i++)
        {
            if(num(i)>x)
            {
                printf("%d\n",i-1);
                break;
            }
        }
    }
    return 0;
}
