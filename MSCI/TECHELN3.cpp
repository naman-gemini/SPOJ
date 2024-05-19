#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a;
        scanf("%d",&a);
        if(a&1)
        printf("Dexter\n");
        else printf("Mandark\n");
    }
    return 0;
}
