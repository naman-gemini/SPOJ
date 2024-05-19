#include<stdio.h>

int main()
{
    long long int a,b,c;
    while(1)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a == 0 && b == 0 && c==0 ) break;
        if((b-a) == (c -b)) printf("AP %d\n",2*c-b);

        else printf("GP %d\n",(c*(b/a)));
    }
    return 0;
}
