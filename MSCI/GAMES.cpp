#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}


int main()
{
    int t,g;
    char s[50];
    bool flag;
    int num,den,x;
    scanf("%d",&t);
    while(t--)
    {
        flag=true;
        scanf("%s",s);
        int size=strlen(s);
        for(int i=0;i<size;i++) if(s[i]=='.') flag=false;
        if(flag)
        {
            printf("1\n");
            continue;
        }
        num=0;
        x=1;
        den=1;

        for(int i=size-1;s[i]!='.';i--)
        {
            num+=den*(s[i]-'0');
            den*=10;
        }

        g=gcd(num,den);
        num/=g;
        den/=g;

        printf("%d\n",den);
    }
}
