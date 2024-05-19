#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[50];
    int t,res;
    scanf("%d",&t);
    while(t--)
    {
        res=1;
        scanf("%s",s);
        for(int i=1; i<strlen(s); i++)
        {
            if(s[i]==s[i-1])
            res*=2;
        }
        printf("%d\n",res);
    }
    return 0;
}
