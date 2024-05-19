#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int zero=1,one=1,temp;

    for(int i=2;i<=n;i++)
    {
        temp=zero;
        zero+=one;
        one+=2*temp;
    }

    printf("%d\n",2*zero+one);
    return 0;
}
