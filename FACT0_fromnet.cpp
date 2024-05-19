#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <time.h>

//typedef __int64 int64;
/*struct timer
{
    clock_t t;
    timer()
    {
        t = clock();
    }
    ~timer()
    {
        printf("runtime %.3f secs\n", getTime());
    }
    double getTime()
    {
        return
            ((double)clock()-(double)t)/(double)CLOCKS_PER_SEC;
    }
};*/

void get_divisors(long long n)
{
    if (!(n&1))
    {
        int np=1;
        while (n/=2, !(n&1))
            ++np;
        printf("2^%d ", np);
    }
    if (!(n%3))
    {
        int np=1;
        while (n/=3, !(n%3))
            ++np;
        printf("3^%d ", np);
    }
    long long p=1, a=2;
    while (a=6-a, p+=a, p*p<=n)
    {
        if (!(n%p))
        {
            int np=1;
            while (n/=p, !(n%p))
                ++np;
            printf("%lld^%d ", p, np);
        }
    }
    if (n>1)
        printf("%lld^1 ", n);
    printf("\n");
}

int main()
{
    //timer t;
    //get_divisors(3111989);
    //get_divisors(13091989);
    //get_divisors(2432902008176640000);
    //get_divisors(77145199750673);

    long long n;
    while(true)
    {
        if(n==0) break;
        scanf("%lld",&n);
        get_divisors(n);
    }

    return 0;
}

/*
3111989 = 317^1 9817^1
13091989 = 17^2 89^1 509^1
2432902008176640000 = 2^18 3^8 5^4 7^2 11^1 13^1 17^1 19^1
77145199750673 = 328439^1 234884407^1
runtime 0.048 secs
Press any key to continue
*/
