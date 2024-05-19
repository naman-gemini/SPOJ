#include<stdio.h>

void main()

{
    int N,M,H,t,m,h,counter=0;

    scanf("%d",&N);
    scanf("%d",&M);
    scanf("%d",&H);
    while (N--)
    {
        scanf("%d",&t);
        scanf("%d",&m);
        scanf("%d",&h);

        if(H>=t)
        {
            if(M>=m)
            {
                counter++;
				printf("%d\t",counter);
                M-=m;
				printf("%d\t",M);
                H+=h;
				printf("%d\t",H);
            }
            else
            continue;
        }

        else
        continue;

    }
    printf("%d\n",counter);
}
