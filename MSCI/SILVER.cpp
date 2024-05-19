#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t;
    while(1)
    {
        scanf("%d",&t);
        if(t==0) return 0;
        printf("%d\n",int(log2(t)));
    }
    return 0;
}
