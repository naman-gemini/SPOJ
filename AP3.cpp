#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    unsigned long long a,b,c;
    unsigned long long term=0;
    while(t--)
    {
        unsigned long long a1,n,d;
        scanf("%llu %llu %llu",&a,&b,&c);
        n=(unsigned long long)((7+(2*(c-b))/(a+b))/2+sqrtl((3.5+(c-b)/(a+b))*((3.5+(c-b)/(a+b))-12*c/(a+b))));
        d=(unsigned long long)((b-a)/(n-6));
        a1=(unsigned long long)(a-(2*d));

        term=a1;

        printf("%llu\n",n);
        //return 0;
        for(long long i=0; i<n; i++)
        {
            term=term+d;
            printf("%llu ",term);
        }
        printf("\n");
    }
    return 0;
}
