#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a,int b)
{
    int t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
    int t,a,b,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=2;
        scanf("%d %d",&a,&b);
        int n=gcd(a,b);
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        int root=int(sqrt(n));
        for(int i=2; i<=root; i++)
        {
            if(n%i==0)
            if(i*i==n) ans++;
            else ans+=2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
