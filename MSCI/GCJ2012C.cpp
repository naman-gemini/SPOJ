#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int number(int a)
{
    int cnt=0;
    while(a)
    {
        a/=10;
        cnt++;
    }
    return cnt;
}

int main()
{
    int power10[]={1,10,100,1000,10000,100000,1000000};
    int t,cs;
    int a,b;
    int count,ans;
    int div,rem;
    int permutation,num;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        ans=0;
        scanf("%d %d",&a,&b);
        for(int i=a;i<=b;i++)
        {
            count=0;
            num=power10[number(i)-1];
            permutation=i;
            while(1)
            {
                div=permutation/10;
                rem=permutation%10;
                permutation=rem*num+div;
                if(permutation==i) break;
                if(rem>0 && permutation>=a && permutation<=b) count++;
            }
            ans+=count;
        }
        ans/=2;
        printf("Case #%d: %d\n",cs,ans);
    }
    return 0;
}
