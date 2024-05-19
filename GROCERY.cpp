#include <cstdio>
using namespace std;
int main()
{
    for (int a=1; a<=500; ++a)
        for (int b=a; b<=(2000-a)/3; ++b)
            for (int c=b; c<=(2000-a-b)/2; ++c)
            {
                int s = 1000000*(a+b+c), p = a*b*c-1000000;
                if (p <= 0 || s % p != 0) continue;
                int d = s/p;
                if (d < c || a+b+c+d > 2000) continue;
                printf("%.2f %.2f %.2f %.2f\n",a/100.0,b/100.0,c/100.0,d/100.0);
            }
    return 0;
}
