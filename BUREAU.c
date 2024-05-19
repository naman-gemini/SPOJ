#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        int a[100000]={0};
        int u[100000]={0};
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            char com[10];
            scanf("%s", com);
            if (strcmp(com, "declare") != 0)
                scanf("%d", &a[i]), a[i]--;
            else
                a[i] = -1;
        }
        for (i = n - 1; i >= 0; i--)
            if (a[i] != -1 && !u[i])
                u[a[i]] = 1;

        int count = 0;

        for (i = 0; i < n; i++)
        count += !u[i];

        printf("%d\n", count);

        for (i = 0; i < n; i++)
        if (!u[i])
            printf("%d ", i + 1);
        printf("\n");
    }

    return 0;
}
