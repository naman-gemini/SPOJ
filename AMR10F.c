#include<stdio.h>

void main()
{
    int T,N,A,D;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        scanf("%d",&A);
        scanf("%d",&D);

        printf("%d\n", N*(2*A+(N-1)*D)/2);
    }
}
