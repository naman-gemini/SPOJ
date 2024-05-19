#include<cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,x,count=0;
        scanf("%d %d",&a,&b);
        for(int i=a;i<=b;i++)
        {
            if(i%11==10)
            {
                x=i;
                break;
            }
        }
        for(int i=x;i<=b;i+=11)
        {
            if(i%11==10)
            count++;
        }
        printf("%d\n",count);

    }
    return 0;
}
