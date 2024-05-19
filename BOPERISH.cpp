#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int i, N;
    while (1)
    {
        scanf("%d", &N);
        int input[N];
        if (N == 0)
            break;
        for (i = 0; i < N; i++)
            scanf("%d", &input[i]);
        sort(input, input + N);
        for (i = N; i >= 1; i--)
        {
            if (input[N - i] >= i)
                break;
        }
        printf("%d\n", i);
    }
    return 0;
}
