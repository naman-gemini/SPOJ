#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

typedef struct
{
    int w,h;
} doll;

doll DOLL[20005];

int compare_w(const void* a,const void* b)
{
    doll *x=(doll *) a;
    doll *y=(doll *) b;
    return (x->w - y->w);
}

int compare_h(const void* a,const void* b)
{
    doll *x=(doll *) a;
    doll *y=(doll *) b;
    return (x->h - y->h);
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int count_w=1,count_h=1;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&DOLL[i].w,&DOLL[i].h);
        }

        qsort(DOLL,n,sizeof(doll),compare_w);

        for(int i=0;i<n;i++)
        {
            if(DOLL[i-1].w>DOLL[i].w || DOLL[i-1].h>DOLL[i].h) count_w++;
        }

        qsort(DOLL,n,sizeof(doll),compare_h);
        for(int i=0;i<n;i++)
        {
            if(DOLL[i-1].w>DOLL[i].w || DOLL[i-1].h>DOLL[i].h) count_h++;
        }

        printf("%d\n",min(count_w,count_w));
    }
    return 0;
}
