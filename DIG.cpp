#include<cstdio>
#include<iostream>
#define MOD 1000000007
using namespace std;

bool fx(int n,int k)
{
    if(n%k==0)
    return true;
    else
    return false;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d;
        bool flag_a=true,flag_b=true,flag_c=true;

        scanf("%d",&n);
        if(n==1 || n==2 || n==3) {printf("0\n");continue;}
        if (fx(n,4)) {a=n/4;flag_a=false; goto pointb;}
        else if (fx(n,3)) {a=n/3;flag_b=false; goto pointb;}
        else if (fx(n,2)) {a=n/2;flag_c=false; goto pointb;}
        else a=n;

        pointb:
        if (flag_a && fx(n-1,4)) {b=(n-1)/4;flag_a=false; goto pointc;}
        else if (flag_b && fx(n-1,3)) {b=(n-1)/3;flag_b=false; goto pointc;}
        else if (flag_c && fx(n-1,2)) {b=(n-1)/2;flag_c=false; goto pointc;}
        else b=n-1;

        pointc:
        if (flag_a && fx(n-2,4)) {c=(n-2)/4;flag_a=false; goto pointd;}
        else if (flag_b && fx(n-2,3)) {c=(n-2)/3;flag_b=false; goto pointd;}
        else if (flag_c && fx(n-2,2)) {c=(n-2)/2;flag_c=false; goto pointd;}
        else b=n-2;

        pointd:
        if (flag_a && fx(n-3,4)) {d=(n-3)/4;flag_a=false;}
        else if (flag_b && fx(n-3,3)) {d=(n-3)/3;flag_b=false;}
        else if (flag_c && fx(n-3,2)) {d=(n-3)/2;flag_c=false;}
        else d=n-3;

        //printf("%d %d %d %d\n",a,b,c,d);

        printf("%d\n", (((a%MOD * b%MOD)%MOD)* ((c%MOD * d%MOD)%MOD))%MOD);
    }
    return 0;
}
