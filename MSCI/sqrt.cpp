#include<cstdio>
#include<iostream>
using namespace std;

int int_sqrt(int n)
{
    int lo,mi,hi;
    lo=0;
    for(hi=1;hi*hi<=n;hi*=2);
    while(lo<hi-1)
    {
        mi=(lo+hi)/2;
        if(mi*mi<=n) lo=mi;
        else hi=mi;
    }
    return lo;
}

int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",int_sqrt(n));
    }
}
