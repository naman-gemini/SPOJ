#include<cstdio>
using namespace std;

int arr[55];

void init()
{
    for(int i=0;i<55;i++)
    {
        arr[i]=0;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        int a,n=1,x=0;
        scanf("%d",&a);
        while(x<a)
        {
            x=pow(2,n+1)-2;
            n++;
        }

    }
}
