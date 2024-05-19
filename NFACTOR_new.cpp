#include <iostream>
using namespace std;
const int N = 10000000;

int f[N+1];

int main()
{
    for (int i = 2; i <= N; i++)
    {
        if (!f[i])
        for (int j = i; j <= N; j += i)
        f[j]++;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;

        int all = 0;
        while (a <= b)
        {
            if (f[a++] == n)
            all++;
        }

        cout << all << endl;
    }
    return 0;
}
