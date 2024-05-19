#include<stdio.h>

int main()
{
    float t,i,n,j,dice;
    scanf("%f",&t);
    for(i=0; i<t; i++)
    {
        scanf("%f",&n);
        dice=0;
        for(j=1; j<=n; j++)
        {
            dice=dice+(n/j);
        }
        printf("%0.2f\n",dice);
    }
    return 0;
}
