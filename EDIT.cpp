#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
    char s[1001];
    int u=0,l=0,t;
    while(scanf("%s",s)!=EOF)
    {
        //printf("%s",s);
        int z=strlen(s);
        for(int i=0; i<z; i++)
        {
            t=i%2;
            if(s[i]>='a') if(t==0) u++;                 //lower case
                else l++;
            if(s[i]<'a') if(t==0) l++;                  //upper case
                else u++;
            //printf("%d %d\n",u,l);
        }
        if(u<l)
            printf("%d\n",u);
        else
            printf("%d\n",l);
        u=0;
        l=0;
    }
    return 0;
}
