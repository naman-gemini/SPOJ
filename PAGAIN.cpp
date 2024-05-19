#include <stdio.h>
#include <stdlib.h>

unsigned long long mulmod(unsigned long long a,unsigned long long b,unsigned long long c)
{
    unsigned long long x = 0, y = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % c;
        }
        y = (y * 2) % c;
        b /= 2;
    }
    return x % c;
}

unsigned long long modulo(unsigned long long a,unsigned long long b,unsigned long long c)
{
    unsigned long long x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            //x = mulmod(x, y, c);
            x = (x*y)%c;
        }
        //y = mulmod(y, y, c);
        y = (y*y)%c;
        b /= 2;
    }
    return x % c;
}

bool Miller(long long p, int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2 == 0)
    {
        return false;
    }
    unsigned long long s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        unsigned long long a = rand() % (p - 1) + 1, temp = s;
        unsigned long long mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            //mod = mulmod(mod, mod, p);
            mod = (mod*mod)%p;
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int k;
    scanf("%i", &k);
    while (k--)
    {
        unsigned long long int a = 0;
        scanf("%llu", &a);

         if(a==3)
        {
            puts("2");
            continue;
        }

        a--;

        if (a % 2 == 0 && a != 2)
            a--;
        while (!Miller(a, 5))
        {
            a -= 2;
        }

        printf("%llu\n", a);
    }
    return 0;
}

