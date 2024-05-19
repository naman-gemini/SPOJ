#include <cstdio>
using namespace std;
int main()
{
    int s,p,x,y;
    int count=0;
    for (int a=1; a<=125; a++)
    {
        x=(2000-a)/3;
        for (int b=a; b<=x; b++)
        {
            y=(2000-a-b)/2;
            for (int c=b; c<=y; c++)
            {
                s = 1000000*(a+b+c), p = a*b*c-1000000;
                if (p <= 0 || s % p != 0) continue;
                int d = s/p;
                if (d < c || a+b+c+d > 2000) continue;
                count++;
                printf("%.2f %.2f %.2f %.2f\n",a/100.0,b/100.0,c/100.0,d/100.0);
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
