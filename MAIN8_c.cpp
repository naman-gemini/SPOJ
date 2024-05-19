#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int N,K,t,i,j,k,ar[50010];
int solve(int x)
{
    k=K;
    for(i=N-1;i>=0;i--)
    {
        k-=(ar[i]/x);
        if(k<=0) return 1;
    }
    return 0;
}
int binarySearch()
{
    int low=1,high=ar[N-1]+1;
    int mid;
    while(low<high)
    {
        mid=(low+high)>>1;
        if(solve(mid)) low=mid+1;
        else high=mid;

    }
    return low-1;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&N,&K);
        for(i=0;i<N;i++) scanf("%d",&ar[i]);
        sort(ar,ar+N);
        printf("%d\n",binarySearch());
    }
    return 0;
}
