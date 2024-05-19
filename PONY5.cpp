#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,*p,n;
        scanf("Case #%d: %d",&i,&n);
        p=(int*)malloc(n*sizeof(int));
        for(int j=0; j<n; j++)
        {
            scanf("%d",&p[j]);
        }
        for(int j=2; j<n; j++)
        {
            for(int k=0; k<10e6; k++)
            {
                p[j]%k==cur;
            }
        }
    }
}
