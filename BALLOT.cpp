#include<iostream>
#include<cstdio>
using namespace std;

int n,b;
int population[500000];


int read_input()
{
    scanf("%d %d",&n,&b);
    if(n==-1) return 0;

    for(int i=0; i<n; i++)
        scanf("%d",&population[i]);

    return 1;
}

bool possible(int x)
{
    int minb = 0;

    for(int i=0; i<n; i++)
    {
        int mx = population[i]/x  + (population[i]%x != 0);

        minb += mx;

        if(minb > b) return false;
    }

    return true;
}

int solve()
{

    int lo = 0;
    int hi = 5000000;

    while(hi > lo+1)
    {
        int mid = (hi+lo)/2;

        if(possible(mid))
        {
            hi = mid;
        }

        else
        {
            lo = mid;
        }
    }

    return hi;
}

int main()
{
    while(read_input())
    {
        int res = solve();
        printf("%d\n",res);

    }

    return 0;
}

