#include<cstdio>
using namespace std;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1) {printf("2\n"); continue;}
        if(n==2) {printf("3\n"); continue;}
        int a=2,b=3,temp;
        for(int i=3;i<=n;i++)
        {
            temp=b;
            b+=a;
            a=temp;
        }
        printf("%d\n",b);
    }
    return 0;
}
