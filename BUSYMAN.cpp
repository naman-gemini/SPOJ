#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

int find_min(int a[],int n)
{
    int min=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>min)
        min=a[i];
    }
    return min;
}

int find_pos(int a[],int n,int min)
{
    int pos=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==min)
        return i;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int *start,*end;
        start=(int*)malloc(sizeof(int)*n);
        end=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&start[i],&end[i]);
        }
        int min_val,pos;

        min_val=find_min(end,n);

    }
}
