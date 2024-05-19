#include<cstdio>

int main()
{
    int a[4] = {1,1,1,1};
    int b[4];

    int sum=0;

    while(sum != 4)
    {
        for(int i=0; i<4; i++)
            printf("%d ",a[i]);

        printf("\n");
        fflush(stdout);

        sum = 0;
        for(int i=0; i<4; i++)
        {
            scanf("%d",&b[i]);
            if(b[i] != 1) a[i]++;
            sum += b[i];
        }
    }
    return 0;
}
