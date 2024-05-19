#include<cstdio>
using namespace std;

int main()
{
    int t,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&t);
        if(t%2==0)
        printf("%d\n",t/2);
        else
        printf("%d\n",t/2+1);
    }
    return 0;
}
