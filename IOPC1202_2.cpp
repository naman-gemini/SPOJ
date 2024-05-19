#include <cstdio>
#include <algorithm>
using namespace std;

#define MOD 100000007
int x[4], y[4];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        for (int i = 0; i < 4; ++i)
        {
            scanf("%d%d", x+i, y+i);
        }
        int low = 0, right = 0;

        for (int i = 1; i < 4; ++i)
        {
            if (y[i] < y[low] || y[i] == y[low] && x[i] < x[low])
            {
                low = i;
            }
            if (x[i] > x[right] || x[i] == x[right] && y[i] < y[right])
            {
                right = i;
            }
        }
        long long dx = x[right] - x[low];
        long long dy = y[right] - y[low];
        long long gc = __gcd(dx, dy);
        gc *= 4;
        long long S = dx * dx + dy * dy;
        long long I = S - gc / 2 + 1;
        I %= MOD;
        S %= MOD;
        I *= 2 * S;
        I %= MOD;
        printf("%d\n", (int)I);
    }
    return 0;
}
