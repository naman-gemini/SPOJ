#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>

using namespace std;

int main()
{
    int t;
    map<int,int> a;
    scanf("%d",&t);
    int n;
    char s[10];
    //cs means single instance
    //cd means double instance (or more)
    int cd=0,cs=0;
    while(t--)
    {
        scanf("%s %d",s,&n);
        if(s[0]=='i')
        {
            if(a[n]==0) cs++;
            if(a[n]>=1) cd++;
            a[n]++;
        }

        else
        {
            if(a[n]>0)
            {
                if(a[n]>1) cd--;
                if(a[n]==1) cs--;
                a[n]--;
            }
        }

        if(cs>=2&&cd>=1)
        {
            printf("both\n");
        }
        else if(cs>=2&&cd==0)
        {
            printf("hetero\n");
        }
        else if( (cs==0 || cs==1) &&cd>=1)
        {
            printf("homo\n");
        }
        else
        {
            printf("neither\n");
        }
    }
    a.clear();
    return 0;
}
