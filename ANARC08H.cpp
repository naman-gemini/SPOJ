#include <stdio.h>
typedef long LL;

int main()
{
    LL n, k, ans, i;

    while (1)
    {
        scanf("%ld %ld", &n, &k);
        if (n == 0 && k == 0)
            break;
        ans = 0;
        for (i = 1; i < n; i++)
        {
            ans = (ans + k) % (i + 1);
        }
        printf("%ld %ld %ld\n", n, k, ans + 1);
    }
    return 0;
}
